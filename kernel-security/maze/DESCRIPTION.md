当前挑战关卡需理解并掌握 Linux Kernel DirtyPipe 即 [CVE-2022-0847][1] 漏洞利用。

- [pipe-primitive][2] - 一种衍生于 DirtyPipe 的利用思路

  - Linux 内核申请 `pipe` 结构体时会默认分配 `kmalloc-1024` 大小的 `pipe_buffer` 对象。
  
  - `splice` 系统调用可以将 `pipe` 与文件 (`fd`) 连接在一起，相当于 `pipe_buffer->page = fd->page` 。
  
  - 当 `pipe_buffer->flags` 为 `PIPE_BUF_FLAG_CAN_MERGE` 时，可以绕过页面权限检查，往 `pipe_buffer->page` 追加续写内容，从而实现对只读文件的任何写操作。
  
  - 仅需利用 `UAF` 漏洞改写 `pipe_buffer->flags` 为 `PIPE_BUF_FLAG_CAN_MERGE`，即可通过覆盖 `SUID` 程序实现权限提升。

- 使用 VM 操作挑战关卡中的 QEMU 虚拟机的相关步骤请查看教学关卡 `vm`。

- 成功启动 QEMU 虚拟机 并进入后，`/dev/maze` 为隐含漏洞的文件

- QEMU 虚拟机内核版本为 `linux-5.10.202`。

- 以下缓解机制已被禁用：
  - `CONFIG_SLAB is not set`
  - `CONFIG_SLAB_FREELIST_RANDOM is not set`
  - `CONFIG_SLAB_FREELIST_HARDENED is not set`
  - `CONFIG_MEMCG is not set`
  - `CONFIG_DEBUG_LIST is not set`


本次挑战，像所有其他挑战一样，位于 `/challenge` 目录中，挑战程序是 `/challenge/solve`。

[1]: https://dirtypipe.cm4all.com/
[2]: https://github.com/veritas501/pipe-primitive