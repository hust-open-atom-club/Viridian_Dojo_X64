当前挑战关卡需理解并掌握 Linux Kernel 空指针解引用漏洞利用。

- 使用 VM 操作挑战关卡中的 QEMU 虚拟机的相关步骤请查看教学关卡 `vm`。

- 成功启动 QEMU 虚拟机 并进入后，`/dev/null_act` 为隐含漏洞的文件。

- QEMU 虚拟机内核版本为 `linux-5.0-rc1`。

- 缓解机制 `CONFIG_DEFAULT_MMAP_MIN_ADDR` 已被设置为 `0`，且 `SMAP/SMEP` 均已禁用。

本次挑战，像所有其他挑战一样，位于 `/challenge` 目录中，挑战程序是 `/challenge/solve`。