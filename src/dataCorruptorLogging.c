//write to the log,
void writeDCKillToLog(int wodAction, int success, int id, int actionCode)
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

void writeMsgQueueDeleteToLog(int wodAction, int success)
{
  FILE* fp = fopen (LOG_FILE_PATH, "a");
  fprintf(fp, "[%s] : WOD Action %d - Delete the Message Queue\n",getTime(), wodAction);
  fprintf(fp, "[%s] : DX deleted the msgQ – the DR/DCs can’t talk anymore - exiting\n", getTime());
  fclose(fp);
}

void writeDidNothingToLog(int wodAction)
{
  FILE* fp = fopen (LOG_FILE_PATH, "a");
  fprintf(fp, "[%s] : WOD Action %d - Did Nothing\n", getTime(), wodAction);
  fclose(fp);
}

void writeMsgQueueGoneToLog(void)
{
  FILE* fp = fopen (LOG_FILE_PATH, "a");
  fprintf(fp, "[%s] : DX detected that msQ is gone - assuming DR/DCs done\n");
  fclose(fp);
}
