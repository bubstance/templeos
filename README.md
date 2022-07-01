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

#### To install a different version of TempleOS

Change the name of the `TempleOS.ISO` to `TempleOS.ISO.bak` and then change the name of either `TinkerOS.ISO` or `Shrine.ISO` to `TempleOS.ISO`. Run the scripts as described above.

##### Bonus Tip!

If you install `TinkerOS.ISO` and set at least one of your drive's graphics mode to `15` during installation, you can then edit the `config.sh` file's QEMU flags to `-display curses` instead of all the
gtk and kvm stuff. Keep the rest, though. ;)
