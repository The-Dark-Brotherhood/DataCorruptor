
int main(int argc, char* argv)
{
  //to get the key
  key_t shmKey = ftok(“.”, 16535);

  for(int i = 0; i < 100; i++)
  {
    // Grabs the shared memory ID
    if(shmID = shmget(shmKey, sizeof(MasterList), 0) != -1)
    {
      break;
    }
    sleep(10);
  }

  // Share mem not found after number tries
  if(shmID == -1)
  {
    return 1;
  }

  MasterList* shList = (MasterList*)shmat (shmID, NULL, 0); // Grabs the shared memory
  if*(shList == NULL)
  {
    printf("Cannot attach to shared memory\n");
    return 2;
  }

  return 0;
}

void corrupterProcessing(int shmKey)
{
  //Step 1: sleep for 10-30 seconds
  srand(time(0));
  sleep((rand() % 21)+10);
  //Step 2: Check for existance of message queue
  //Step 3: Select and action from WOD
  int randomAction = spinTheWheelOfDestruction();
  //Step 4: Execute Action
  executeAction(randomAction);
}

int spinTheWheelOfDestruction(void)
{
  //Get a value between 0-20
  int randomAction = ((rand()%21));
  return randomAction;
}

void executeAction(int action)
{
  int actionCode = 0;
  int dcID = 0;
  switch(action)
  {
    case 0||8||19:
    //do nothing
      break;
    case 1||4||11:
    //kill 1st
      break;
    case 2||5||15:
    //kill 3rd
      break;
    case 3||6||13:
    //kill 2nd
      break;
    case 7:
    //kill 4th
      break;
    case 9:
    //kill 5th
      break;
    case 10||17:
    //kill message queue
      break;
    case 12:
    //kill 6
      break;
    case 14:
    //kill 7
      break;
    case 16:
    //kill 8
      break;
    case 18:
    //kill 9
      break;
    case 20:
    //kill 10
      break;
    default:
    //error
  }
  writeToLog(action, )
}

//write to the log,
void writeToLog(int wodAction, int success, int id, int actionCode)
{
  char description[255] = "";
  FILE * fp = fopen (LOG_FILE_PATH, "a");
  switch(actionCode)
  {
    case -2:
      //detected queue no longer exists
      fprintf(description, "[%s] : DX detected that msQ is gone - assuming DR/DCs done\n");
      break;
    case -1:
      //deleted queue
      fprintf(description, "[%s] : WOD Action %d - Delete the Message Queue\n",getTime(), wodAction);
      break;
    case 0:
    / /did nothing
      fprintf(description, "[%s] : WOD Action %d - Did Nothing\n", getTime(), wodAction);
      break;
    case 1..10:
      fprintf(description, "[%s] : WOD Action %d - DC-%02d [%d] TERMINATED\n", getTime(), wodAction, id);
      break;
  }
  fclose(fp);
}
