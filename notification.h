#ifndef FAYT_NOTIFICATION_H_
#define FAYT_NOTIFICATION_H_

struct notification_info {

}; 
	
struct notification_action {
	void (*handler)(struct notification_info*, void*, int);
};

#endif
