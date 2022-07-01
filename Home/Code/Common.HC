// Here we keep common code that is 
// shared across all of the solutions 

class SV {
  I64 size;
  U8 *begin;
};

I64 SVChopI64(SV *sv, I64 radix=10) {
  U8 *endp;
  I64 result = Str2I64(sv->begin, radix, &endp);
  sv->size -= endp - sv->begin;
  sv->begin = endp;
  return result;
}

Bool IsAlpha(U8 x) {
  return ('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z');
}

Bool IsDigit(U8 x) {
  return '0' <= x && x <= '9';
}

Bool IsAlnum(U8 x) {
  return IsAlpha(x) || IsDigit(x);
}

Bool IsSpace(U8 x) {
  return x == ' ' || x == '\n';
}

U0 SVTrimLeft(SV *sv) {
  I64 i = 0;
  while (i < sv->size && IsSpace(sv->begin[i])) {
    i++;
  }  
  sv->begin += i;
  sv->size  -= i;
}

U0 SVChopWord(SV *input, SV *word) {
  I64 i = 0;
  while (i < input->size && IsAlnum(input->begin[i])) {
    i++;
  }
  word->begin = input->begin;
  word->size = i;
  input->begin += i;
  input->size -= i;
}

U0 SVChopLeft(SV *sv, I64 n=1)
{
  sv->begin += n;
  sv->size -= n;
}

U0 SVChopByDelim(SV *sv, U8 delim, SV *out)
{
  I64 i=0;
  while (i<sv->size && sv->begin[i] != delim) i++;

  out->begin = sv->begin;
  out->size = i;
  
  if (i<sv->size) {
    sv->begin += i+1;
    sv->size -= i+1;
  } else {
    sv->begin += i;
    sv->size -= i;
  }
}

U0 PrintSV(SV *sv)
{
  I64 i;
  for (i=0; i<sv->size; ++i)
    Print("%c", sv->begin[i]);
}

Bool SVEq(SV *a, SV *b)
{
  if (a->size == b->size) {
    return MemCmp(a->begin, b->begin, a->size) == 0;
  }

  return FALSE;
}

Bool SVEqCstr(SV *a, U8 *b)
{
    SV c;
    c.begin = b;
    c.size = StrLen(b);
    return SVEq(a, &c);
}

#ifdef BLASPHEMY
Bool SVEqCstr(SV *a, const char *b)
{
    return SVEqCstr(a, (U8*) b);
}
#endif
