#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>

// Constants
#define KEY_PATH     "/tmp/"
#define ID_ERROR      -1
#define SHM_KEYID     16535
#define EXIT_CODE     6
#define LOG_FILE_PATH "/tmp/dataCorruptor.log"

// in seconds
#define TIMEOUT       5       // DEBUG: CHANGE LATER
#define EXIT_DELAY    10      // DEBUG: Check if this is right for closing the server
#define MSG_DELAY     1.5

// Structuress
//--> Message QUEUE
typedef struct
{
  long msgType;
  pid_t clientId;
  int msgStatus;
} msgData;

//--> Shared Memory
#define MAX_DC_ROLES  10
//--> Shared Memory

typedef struct DCInfo
{
  pid_t dcProcessID;
  time_t lastTimeHeardFrom;
} DCInfo;

typedef struct
{
  int msgQueueID;
  int numberOfDCs;
  DCInfo dc[MAX_DC_ROLES];
} MasterList;


// Function Prototypes
void writeDCKillToLog(int wodAction, int success, int id, int DCNum);
MasterList* attachToSharedMemory(int shmID);
void corrupterProcessing(MasterList* shList,key_t shmKey);
int spinTheWheelOfDestruction(void);
int killTheThing(MasterList* list, int index);
int executeAction(MasterList* list, int action);
void writeMsgQueueDeleteToLog(int wodAction, int success);
void writeDidNothingToLog(int wodAction);
void writeMsgQueueGoneToLog(void);
void getTime(char* output);
