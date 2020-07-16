#ifndef __LINUX_THERMAL_NOTIFY_H
#define __LINUX_THERMAL_NOTIFY_H

#include <linux/notifier.h>

/* the cpus are becoming hot */
#define THERMAL_EVENT_CPUS_HOT		0x01
/* the cpus are becoming hotter */
#define THERMAL_EVENT_CPUS_HOTTER	0x02
/* the cpus have hit the thermal limit */
#define THERMAL_EVENT_CPUS_LIMIT_HIT	0x03
/* the cpus are in the temperature limit */
#define THERMAL_EVENT_CPUS_COLD		0x04

struct thermal_event {
	void *data;
};

#ifdef CONFIG_THERMAL_NOTIFICATION
int thermal_register_client(struct notifier_block *nb);
int thermal_unregister_client(struct notifier_block *nb);
int thermal_notifier_call_chain(unsigned long val, void *v);
#else
static int inline thermal_register_client(struct notifier_block *nb)
{
	return -ENOENT;
}
static int inline thermal_unregister_client(struct notifier_block *nb)
{
	return -ENOENT;
}
static int inline thermal_notifier_call_chain(unsigned long val, void *v)
{
	return -ENOENT;
}
#endif
#endif /* _LINUX_THERMAL_NOTIFY_H */

