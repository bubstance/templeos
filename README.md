# [Advent of Code 2021](https://adventofcode.com/) solutions in [TempleOS](https://templeos.org/)

*For how to get the same color theme, see [./Home/Theme.HC](./Home/Theme.HC)*

## Quick Start

### Dependencies

- [QEMU](https://www.qemu.org/)
- [rsync](https://rsync.samba.org/)

### Configuration

All of the scripts use configuration from the `config.sh` script. Open it and customize it to your liking. (I'd recommend not changing anything, but who am I to tell you what to do?)

### TempleOS Installation

```console
$ ./install.sh ./name.img
... Follow the Installer instructions, but don't reboot at the end. Just close the VM ...
$ ./sync.sh temple ./name.img
```

### Running

```console
$ ./run.sh ./name.img
... Boot the C drive ...
```

### Mounting the File System

```console
$ ./mount.sh ./name.img
$ cd ./mnt/
```

You can run `./mount.sh` script several times, it unmounts the image before trying to mount it again. Also the `run.sh` also unmounts the image before running the VM. You usually never have to unmount it manually, but if you need to you can always do `sudo umount ./mnt/`.

### Sync the Home between the Host and the Temple

The subcommand (`temple` or `host`) basically denotes the target.

#### From Host to Temple

```console
$ ./sync.sh temple ./name.img
```

#### From Temple to Host

```console
$ ./sync.sh host ./name.img
```
