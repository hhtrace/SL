#include "sl_server_epool.h"
#include <sys/epool.h>

static int listen_fd;
static int epoll_fd;
static int max_events;

int epoll_init(int l_fd, int m_evt)
{
    struct epoll_event event;
    int ret;

    max_events = m_evt;
    if (max_events < 1)
	return -1;

    listen_fd = l_fd;
    if (listen_fd < 0)
	return -1;

    epoll_fd = epoll_create();
    if (epoll_fd == -1)
	return -1;

    memset(&event, 0, sizeof(struct epoll_event));
    event.events |= EPOLLIN;
    event.data.fd = sfd;
    
    ret = epoll_ctl(epoll_fd, EPOLL_CTL_ADD, listen_fd, &event);
    if (ret == -1)
	return -1;

    return 0;
}

void *epoll_master(void *param)
{
    sl_server_tdata_t *tdata = (sl_server_tdata_t*)param;
    sl_server_t *server      = tdata->parent;

    while (1) {
	epoll_produce(
    }
}

int epoll_produce()
{
    int i, nfds;
    struct epoll_event *events = NULL;
 
    events = (struct epoll_event*)malloc(sizeof(struct epoll_event) * max_events);
    if (events == NULL)
	return -1;

    for ( ; ; ) {
	nfds = epoll_wait(epoll_fd, events, max_events, -1);
        
        for (i = 0; i < nfds; i++) {
            if ((events[i].events & EPOLLERR) || (events[i].events & EPOLLHUP)) {
                epoll_del(events[i].data.fd);
		close(events[i].data.fd);

	    } else if (events[i].data.fd == listen_fd) {
		while (1) {
		    addrlen = sizeof(struct sockaddr);
                    fd = accept(listen_fd, &addr, &addrlen);
                    if (fd == -1) {
	                continue;
 	 	    }
	            epoll_add(events[i].data.fd);
    		}


            }


    }
}


int epoll_worker()
{
}