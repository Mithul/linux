#include <linux/kernel.h>
#include <linux/string.h>
#include <uapi/linux/kvm_para.h>

asmlinkage long sys_vcpu_info(void)
{
	int cpu_id;
	trace_printk("Hello world making a hypercall\n");
	for(cpu_id=0; cpu_id<num_online_cpus() ; cpu_id++)
		kvm_hypercall1(KVM_HC_LAB_VCPU_INFO, cpu_id);
        return 0;
}
