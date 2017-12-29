#ifndef __AE_H__
#define __AE_H__

struct aeEventLoop;

/* Types and data structures */
typedef void aeFileProc(struct aeEventLoop *eventLoop, int fd, void *clientData, int mask);
typedef int aeTimeProc(struct aeEventLoop *eventLoop, long long id, void *clientData);
typedef void aeEventFinalizerProc(struct aeEventLoop *eventLoop, void *clientData);


/////////////////////////////////////////////
//文件和时间的操作结构
/* File event structure */
typedef struct aeFileEvent {
    int fd;
    int mask; /* one of AE_(READABLE|WRITABLE|EXCEPTION) */
    aeFileProc *fileProc;                 //操作文件函数
    aeEventFinalizerProc *finalizerProc;  //事件初始化结构
    void *clientData;                     //客户端数据
    struct aeFileEvent *next;             //下一个文件
} aeFileEvent;




//wuyujie
/* Time event structure */
typedef struct aeTimeEvent {
    long long id; /* time event identifier. */
    long when_sec; /* seconds */
    long when_ms; /* milliseconds */
    aeTimeProc *timeProc;
    aeEventFinalizerProc *finalizerProc;
    void *clientData;
    struct aeTimeEvent *next;
} aeTimeEvent;

/* State of an event based program */
typedef struct aeEventLoop {
    long long timeEventNextId; //id 标识
    aeFileEvent *fileEventHead; //文件事件集合
    aeTimeEvent *timeEventHead;  //时间时间集合
    int stop;                    //暂停标志
} aeEventLoop;



/* Defines */
#define AE_OK 0
#define AE_ERR -1

#define AE_READABLE 1
#define AE_WRITABLE 2
#define AE_EXCEPTION 4

#define AE_FILE_EVENTS 1
#define AE_TIME_EVENTS 2
#define AE_ALL_EVENTS (AE_FILE_EVENTS|AE_TIME_EVENTS)
#define AE_DONT_WAIT 4

#define AE_NOMORE -1

/* Macros */
#define AE_NOTUSED(V) ((void) V)

/* Prototypes */
//创建事件集合
aeEventLoop *aeCreateEventLoop(void);
//删除 
void aeDeleteEventLoop(aeEventLoop *eventLoop);
//设置stop标识
void aeStop(aeEventLoop *eventLoop);
//创建文件事件
int aeCreateFileEvent(aeEventLoop *eventLoop, int fd, int mask,
                              aeFileProc *proc, void *clientData,
        aeEventFinalizerProc *finalizerProc);

void aeDeleteFileEvent(aeEventLoop *eventLoop, int fd, int mask);

long long aeCreateTimeEvent(aeEventLoop *eventLoop, long long milliseconds,
        aeTimeProc *proc, void *clientData,
        aeEventFinalizerProc *finalizerProc);
int aeDeleteTimeEvent(aeEventLoop *eventLoop, long long id);

int aeProcessEvents(aeEventLoop *eventLoop, int flags);

void aeMain(aeEventLoop *eventLoop);

#endif
