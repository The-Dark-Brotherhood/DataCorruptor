#include "../inc/DataCorruptor.h"


void getTime(char* output)
{
  //Get time info in time_t struct
  time_t rawtime;
  struct tm *info;
  time( &rawtime );
  info = localtime(&rawtime);

  //Set the time output to match the requirements
  //first paramater is where to store outputted string
  strftime(output, 49, "%F %T",info);
}

// FUNCTION      : writeDCKillToLog
// DESCRIPTION   : writes to the log file - when deleting a data creator
//
// PARAMETERS    :
//    int wodAction -> wheel of destruction action
//    int success   -> if the DX was successful in deleting the DC process
//    int id        -> Process ID of the data creator
//
// RETURNS       : none
void writeDCKillToLog(int wodAction, int success, int id, int DCNum)
{
  char time[50] = "";
  getTime(time);

  FILE* fp = fopen (LOG_FILE_PATH, "a");
  if(fp != NULL)
  {
    if(success)
    {
      fprintf(fp, "[%s] : WOD Action %d - DC-%02d [%d] TERMINATED\n", time, wodAction, DCNum, id);
    }
    else
    {
      fprintf(fp, "[%s] : WOD Action %d - DC-%02d FAILED - That Data Creator Doesn't Exist\n", time, wodAction, DCNum);
    }
      //failed to kill, already dead, log
    fclose(fp);
  }
}

// FUNCTION      : writeMsgQueueDeleteToLog
// DESCRIPTION   : writes to the log file - when deleting the message queue
//
// PARAMETERS    :
//    int wodAction -> wheel of destruction action
//    int success   -> if the DX was successful in deleting the DC process
//
// RETURNS       : none
void writeMsgQueueDeleteToLog(int wodAction, int success)
{
  char time[50] = "";
  getTime(time);

  FILE* fp = fopen (LOG_FILE_PATH, "a");
  if(fp != NULL)
  {
    fprintf(fp, "[%s] : WOD Action %d - Delete the Message Queue\n", time, wodAction);
    if(success)
    {
      fprintf(fp, "[%s] : DX deleted the msgQ – the DR/DCs can’t talk anymore - exiting\n", time);
    }
    else
    {
      fprintf(fp, "[%s] : DX unable to delete the msgQ – assuming doesn't exist any more - exiting\n", time);
    }
    fclose(fp);
  }


}

// FUNCTION      : writeDidNothingToLog
// DESCRIPTION   : writes to the log file - when doing nothing
//
// PARAMETERS    :
//    int wodAction -> wheel of destruction action
//
// RETURNS       : none
void writeDidNothingToLog(int wodAction)
{
  char time[50] = "";
  getTime(time);

  FILE* fp = fopen (LOG_FILE_PATH, "a");
  if(fp != NULL)
  {
    fprintf(fp, "[%s] : WOD Action %d - Did Nothing\n", time, wodAction);
    fclose(fp);
  }
}

// FUNCTION      : writeMsgQueueGoneToLog
// DESCRIPTION   : writes to the log file - when DX detected that message queue is gone
//
// PARAMETERS    : none
//
// RETURNS       : none
void writeMsgQueueGoneToLog(void)
{
  char time[50] = "";
  getTime(time);

  FILE* fp = fopen (LOG_FILE_PATH, "a");
  if(fp != NULL)
  {
    fprintf(fp, "[%s] : DX detected that msQ is gone - assuming DR/DCs done\n", time);
    fclose(fp);
  }
}
