#include <linux/kernel.h>
#include <linux/string.h>
//#include <uapi/linux/kvm_para.h>
#include <uapi/linux/kvm.h>
//#include <asm/kvm.h>
#include <linux/kvm_host.h>

void vcpu_info(struct kvm *kvm, int vcpu_id){
	struct kvm_vcpu *kvm_vcpu = kvm_get_vcpu_by_id(kvm, vcpu_id);
	struct kvm_regs *regs = kmalloc(sizeof(struct kvm_regs), GFP_KERNEL);
	kvm_arch_vcpu_ioctl_get_regs(kvm_vcpu, regs);
	trace_printk("cpu:%d, vcpu_id:%d, exits:%llu, REGISTERS:\n", kvm_vcpu->cpu, kvm_vcpu->vcpu_id, kvm_vcpu->stat.exits);
	trace_printk("rax:%llu,  rbx:%llu,  rcx:%llu,  rdx:%llu,  ",regs->rax, regs->rbx, regs->rcx, regs->rdx);
	trace_printk("rsi:%llu,  rdi:%llu,  rsp:%llu,  rbp:%llu,  ",regs->rsi, regs->rdi, regs->rsp, regs->rbp);
	trace_printk("r8:%llu,   r9,:%llu,   r10:%llu,  r11:%llu, ",regs->r8,  regs->r9,  regs->r10, regs->r11); 
	trace_printk("r12:%llu,  r13:%llu,  r14:%llu,  r15:%llu, ",regs->r12, regs->r13, regs->r14, regs->r15);

	kfree(regs);
    
}
