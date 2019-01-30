#ifndef offsets_h
#define offsets_h

extern unsigned off_p_pid;
extern unsigned off_task;
extern unsigned off_p_uid;
extern unsigned off_p_gid;
extern unsigned off_p_ruid;
extern unsigned off_p_rgid;
extern unsigned off_p_ucred;
extern unsigned off_p_csflags;
extern unsigned off_p_comm;

extern unsigned off_itk_self;
extern unsigned off_itk_sself;
extern unsigned off_itk_bootstrap;
extern unsigned off_itk_space;
extern unsigned off_ip_mscount;
extern unsigned off_ip_srights;
extern unsigned off_ip_kobject;
extern unsigned off_p_textvp;
extern unsigned off_p_textoff;
extern unsigned off_p_cputype;
extern unsigned off_p_cpu_subtype;
extern unsigned off_special;
extern unsigned off_ipc_space_is_table;

extern unsigned off_ucred_cr_uid;
extern unsigned off_ucred_cr_ruid;
extern unsigned off_ucred_cr_gid;
extern unsigned off_ucred_cr_rgid;
extern unsigned off_ucred_cr_svgid;
extern unsigned off_ucred_cr_groups;
extern unsigned off_ucred_cr_ngroups;
extern unsigned off_ucred_cr_svuid;
extern unsigned off_ucred_cr_label;

extern unsigned off_amfi_slot;
extern unsigned off_sandbox_slot;

extern unsigned off_v_type;
extern unsigned off_v_id;
extern unsigned off_v_ubcinfo;
extern unsigned off_v_flags;

extern unsigned off_ubcinfo_csblobs;

extern unsigned off_csb_cputype;
extern unsigned off_csb_flags;
extern unsigned off_csb_base_offset;
extern unsigned off_csb_entitlements_offset;
extern unsigned off_csb_signer_type;
extern unsigned off_csb_platform_binary;
extern unsigned off_csb_platform_path;
extern unsigned off_csb_cd;

extern unsigned off_t_flags;

extern unsigned off_v_mount;
extern unsigned off_v_specinfo;
extern unsigned off_specflags;
extern unsigned off_mnt_flag;
extern unsigned off_mnt_data;

#define    CS_VALID        0x0000001    /* dynamically valid */
#define CS_ADHOC        0x0000002    /* ad hoc signed */
#define CS_GET_TASK_ALLOW    0x0000004    /* has get-task-allow entitlement */
#define CS_INSTALLER        0x0000008    /* has installer entitlement */

#define    CS_HARD            0x0000100    /* don't load invalid pages */
#define    CS_KILL            0x0000200    /* kill process if it becomes invalid */
#define CS_CHECK_EXPIRATION    0x0000400    /* force expiration checking */
#define CS_RESTRICT        0x0000800    /* tell dyld to treat restricted */
#define CS_ENFORCEMENT        0x0001000    /* require enforcement */
#define CS_REQUIRE_LV        0x0002000    /* require library validation */
#define CS_ENTITLEMENTS_VALIDATED    0x0004000

#define    CS_ALLOWED_MACHO    0x00ffffe

#define CS_EXEC_SET_HARD    0x0100000    /* set CS_HARD on any exec'ed process */
#define CS_EXEC_SET_KILL    0x0200000    /* set CS_KILL on any exec'ed process */
#define CS_EXEC_SET_ENFORCEMENT    0x0400000    /* set CS_ENFORCEMENT on any exec'ed process */
#define CS_EXEC_SET_INSTALLER    0x0800000    /* set CS_INSTALLER on any exec'ed process */

#define CS_KILLED        0x1000000    /* was killed by kernel for invalidity */
#define CS_DYLD_PLATFORM    0x2000000    /* dyld used to load this is a platform binary */
#define CS_PLATFORM_BINARY    0x4000000    /* this is a platform binary */
#define CS_PLATFORM_PATH    0x8000000    /* platform binary by the fact of path (osx only) */

#define CS_DEBUGGED         0x10000000  /* process is currently or has previously been debugged and allowed to run with invalid pages */
#define CS_SIGNED         0x20000000  /* process has a signature (may have gone invalid) */
#define CS_DEV_CODE         0x40000000  /* code is dev signed, cannot be loaded into prod signed code (will go away with rdar://problem/28322552) */

enum kstruct_offset {
  /* struct task */
  KSTRUCT_OFFSET_TASK_LCK_MTX_TYPE,
  KSTRUCT_OFFSET_TASK_REF_COUNT,
  KSTRUCT_OFFSET_TASK_ACTIVE,
  KSTRUCT_OFFSET_TASK_VM_MAP,
  KSTRUCT_OFFSET_TASK_NEXT,
  KSTRUCT_OFFSET_TASK_PREV,
  KSTRUCT_OFFSET_TASK_ITK_SPACE,
  KSTRUCT_OFFSET_TASK_BSD_INFO,
  KSTRUCT_OFFSET_TASK_ALL_IMAGE_INFO_ADDR,
  KSTRUCT_OFFSET_TASK_ALL_IMAGE_INFO_SIZE,
  
  /* struct ipc_port */
  KSTRUCT_OFFSET_IPC_PORT_IO_BITS,
  KSTRUCT_OFFSET_IPC_PORT_IO_REFERENCES,
  KSTRUCT_OFFSET_IPC_PORT_IKMQ_BASE,
  KSTRUCT_OFFSET_IPC_PORT_MSG_COUNT,
  KSTRUCT_OFFSET_IPC_PORT_IP_RECEIVER,
  KSTRUCT_OFFSET_IPC_PORT_IP_KOBJECT,
  KSTRUCT_OFFSET_IPC_PORT_IP_PREMSG,
  KSTRUCT_OFFSET_IPC_PORT_IP_CONTEXT,
  KSTRUCT_OFFSET_IPC_PORT_IP_SRIGHTS,
  
  /* struct proc */
  KSTRUCT_OFFSET_PROC_PID,
  KSTRUCT_OFFSET_PROC_P_FD,
  KSTRUCT_OFFSET_PROC_TASK,    
  
  /* struct filedesc */
  KSTRUCT_OFFSET_FILEDESC_FD_OFILES,
  
  /* struct fileproc */
  KSTRUCT_OFFSET_FILEPROC_F_FGLOB,
  
  /* struct fileglob */
  KSTRUCT_OFFSET_FILEGLOB_FG_DATA,
  
  /* struct socket */
  KSTRUCT_OFFSET_SOCKET_SO_PCB,
  
  /* struct pipe */
  KSTRUCT_OFFSET_PIPE_BUFFER,
  
  /* struct ipc_space */
  KSTRUCT_OFFSET_IPC_SPACE_IS_TABLE_SIZE,
  KSTRUCT_OFFSET_IPC_SPACE_IS_TABLE,
    
  /* struct vnode */
  KSTRUCT_OFFSET_VNODE_V_MOUNT,
  KSTRUCT_OFFSET_VNODE_VU_SPECINFO,
    
  /* struct specinfo */
  KSTRUCT_OFFSET_SPECINFO_SI_FLAGS,
    
  /* struct mount */
  KSTRUCT_OFFSET_MOUNT_MNT_FLAG,
    
  /* struct host */
  KSTRUCT_OFFSET_HOST_SPECIAL,
  
  KFREE_ADDR_OFFSET,
};

int koffset(enum kstruct_offset offset);
void offsets_init(void);

#endif
