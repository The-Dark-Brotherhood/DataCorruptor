// FUNCTION      : writeDCKillToLog
// DESCRIPTION   : writes to the log file - when deleting a data creator
//
// PARAMETERS    :
//    int wodAction -> wheel of destruction action
//    int success   -> if the DX was successful in deleting the DC process
//    int id        -> Process ID of the data creator
//
// RETURNS       : none
void writeDCKillToLog(int wodAction, int success, int id)
{
  FILE* fp = fopen (LOG_FILE_PATH, "a");
  if(success)
  {
    fprintf(description, "[%s] : WOD Action %d - DC-%02d [%d] TERMINATED\n", getTime(), wodAction, id);
  }
  else
  {
    fprintf(description, "[%s] : WOD Action %d - DC-%02d [%d] FAILED - Data Creator with that PID does not exist\n", getTime(), wodAction, id);
  }
    //failed to kill, already dead, log
  }
  fclose(fp);
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
  FILE* fp = fopen (LOG_FILE_PATH, "a");
  fprintf(fp, "[%s] : WOD Action %d - Delete the Message Queue\n",getTime(), wodAction);
  fprintf(fp, "[%s] : DX deleted the msgQ – the DR/DCs can’t talk anymore - exiting\n", getTime());
  fclose(fp);
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
  FILE* fp = fopen (LOG_FILE_PATH, "a");
  fprintf(fp, "[%s] : WOD Action %d - Did Nothing\n", getTime(), wodAction);
  fclose(fp);
}

// FUNCTION      : writeMsgQueueGoneToLog
// DESCRIPTION   : writes to the log file - when DX detected that message queue is gone
//
// PARAMETERS    : none
//
// RETURNS       : none
void writeMsgQueueGoneToLog(void)
{
  FILE* fp = fopen (LOG_FILE_PATH, "a");
  fprintf(fp, "[%s] : DX detected that msQ is gone - assuming DR/DCs done\n");
  fclose(fp);
}
