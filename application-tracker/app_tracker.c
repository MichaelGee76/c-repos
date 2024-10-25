# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <dirent.h>
#ifdef _WIN32 
  #include <direct.h>
  #define mkdir _mkdir
#else 
  #include <sys/stat.h>
#endif    

enum Status{
  OPEN,
  CLOSED,
  PENDING,
  SUCCESSFUL
};

struct Application {
  int id;
  char* company;
  char* position;
  char* location;
  char* notes;
  enum Status status;
};
int create_folder(void);
int add_application(void);
int amend_application(void);
int list_applications(void);
struct Application create_app(int current_id);
int check_memory_allocation(char* strcut_string, char* name);
int get_max_id();

// global variable
int current_app_id;

int main(){
  int option;
  create_folder();
  current_app_id = get_max_id() +1;
  
  int count = 0;
  do
  {
    if (count == 0){
      printf("\n##########################\n");
      printf("# Welcome to App Tracker #\n");
      printf("##########################\n");
    }
    
    printf("\n\nChoose an option:\n1. Add application\n2. Amend application\n3. Show all applications\n4. Quit\n", count);
    if(scanf("%d", &option) != 1){
      printf("Invalid input. Please enter a number between 1-4.\n");
      int character;
      while((character = getchar()) != '\n' && character != EOF);
      continue;
    }
    
    count++;
    switch (option)
    {
    case 1:
      add_application();
      break;
    case 2:
      amend_application();
      break;
    case 3:
      list_applications();
      break; 
    case 4:
      exit(0);   
    default:
      printf("Only number 1-4 allowed. Try again");
      break;
    }

  } while (option != 4);
  
  exit(0);
};

int create_folder(){
  int check;
  // set dirname
  char* dirname = "appFolder";
  // check if folder exists
  DIR *folder;
  if ((folder = opendir(dirname))){
    printf("# Root folder '%s' exists #\n", dirname);
    closedir(folder);
    return 0;
  }
  // create folder
  check = mkdir(dirname);
  // if successfully created, print
  if(check == 0){
    printf("Folder '%s' created.\n", dirname);
    return 0;
  // else: print
  } else{
    printf("Unable to create folder %s", dirname);
    return -1;
  }
  
}

int add_application(void){
    // open file
    FILE *fptr;
    // char filename = "applications.csv";
    // check if file exists by reading it
    if(fptr = fopen("appFolder/applications.csv", "r")){
      fclose(fptr);
      // if it exists, open in readmode
      fptr = fopen("appFolder/applications.csv", "a");
    }
    // not exist, open in write mode
    else{
      fptr = fopen("appFolder/applications.csv", "w");
    }
    // check if open file failed
    if (fptr == NULL){
      printf("Unable to open folder. Program terminated.");
      return 1;
    }
    // opening successfull
    struct Application new_app = create_app(current_app_id);
      if (!create_app){
        printf("Unable to create app.");
        return 1;
      }

    printf("App successfully created.");  
    // change status code to string
    const char* status_string;
    switch (new_app.status)
    {
    case OPEN : status_string = "OPEN";
      break;
    case CLOSED : status_string = "CLOSED";  
      break;
    case PENDING : status_string = "PENDING";
      break;
    case SUCCESSFUL : status_string = "SUCCESSFUL";
      break;
    default:
      status_string = "UNKNOWN";
      break;
    }
    // write to csv
    fprintf(fptr, "%d,\"%s\",\"%s\",\"%s\",\"%s\",\"%s\"\n",
              new_app.id,
              new_app.company, 
              new_app.position, 
              new_app.location, 
              new_app.notes, 
              status_string);


    // close file
    fclose(fptr);
    // free memory
    free(new_app.company);
    free(new_app.position);
    free(new_app.location);
    free(new_app.notes);
    return 0;
  }

  int amend_application(void){
    FILE *fptr;
    if(fptr = fopen("appFolder/applications.csv", "r")){
      // first print csv data
      char line[600];
      while(fgets(line, sizeof(line), fptr) != NULL){
        printf("%s", line);
      }
      //find the id to amend
      int amend_id;
      printf("\nWhich line you want to amend(enter ID)?\n");
      scanf("%d", &amend_id);
      // back to beginning of data
      rewind(fptr);
      // Set temp data
      FILE *temp_fptr = fopen("appFolder/temp.csv", "w");
      if(temp_fptr == NULL){
        printf("Cannot open temp file.\n");
        fclose(fptr);
        return 1;
      }
      // find line with corresponding id
      while (fgets(line, sizeof(line), fptr) != NULL) {
    char line_copy[600];
    strcpy(line_copy, line);  // get copy of line

    char* token = strtok(line, ",");
    int current_id = atoi(token);

    if(current_id == amend_id) {
        struct Application new_app = create_app(current_id);
        fprintf(temp_fptr, "%d,\"%s\",\"%s\",\"%s\",\"%s\",\"%s\"\n",
            new_app.id,
            new_app.company, 
            new_app.position, 
            new_app.location, 
            new_app.notes, 
            "OPEN");
    }
    else{
        // use copy in case of no changes
        fprintf(temp_fptr, "%s", line_copy);
    }
}

      fclose(fptr);
      fclose(temp_fptr);
      // replace old data with new data
      remove("appFolder/applications.csv");
      rename("appFolder/temp.csv", "appFolder/applications.csv");
      printf("Data successfully amended.\n");
    }
    else{
      printf("File doesn't exist. You need to add an app before.");
    }
    return 0;
  }

  int list_applications(void){
    printf("List of your applications");
    FILE *fptr;
    if(fptr = fopen("appFolder/applications.csv", "r")){
      // first print csv data
      char line[600];
      while(fgets(line, sizeof(line), fptr) != NULL){
        printf("%s", line);
      }
    return 0;
  }}

  struct Application create_app(int current_id){
    
    struct Application app;
    // set app_id to current_app_id and increment
    if (current_id == -1) {
        app.id = current_app_id++;  
    } else {
        app.id = current_id;  
    }
    // clear buffer for what ever reason
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    // company
    app.company = malloc(50 * sizeof(char));
    // check if memory allocation went well
    if(check_memory_allocation(app.company, "company")){
      exit(1);
    }
    printf("Type company name:\n");
    fgets(app.company, 50, stdin);
    app.company[strcspn(app.company, "\n")] = 0;
    // position
    app.position = malloc(50 * sizeof(char));
    if(check_memory_allocation(app.position, "position")){
      exit(1);
    }
    printf("Type position name:\n");
    fgets(app.position, 50, stdin);
    app.position[strcspn(app.position, "\n")] = 0;
    // location
    app.location = malloc(50 * sizeof(char));
    if(check_memory_allocation(app.location, "location")){
      exit(1);
    }
    printf("Type location:\n");
    fgets(app.location, 50, stdin);
    app.location[strcspn(app.location, "\n")] = 0;
    // notes
    app.notes = malloc(255 * sizeof(char));
    if(check_memory_allocation(app.notes, "notes")){
      exit(1);
    }
    printf("Type notes:\n");
    fgets(app.notes, 255, stdin);
    app.notes[strcspn(app.notes, "\n")] = 0;
    // Set status to open
    app.status = OPEN;
    return app;
  }

  int check_memory_allocation(char* struct_string, char* name){
    if (struct_string == NULL) {
        printf("Memory allocation for %s failed!\n", name);
        return 1;
    }
    return 0;
  }
  int get_max_id() {
    FILE *fptr;
    int max_id = 0;
    char line[600];

    if((fptr = fopen("appFolder/applications.csv", "r")) != NULL) {
        while(fgets(line, sizeof(line), fptr) != NULL) {
            char* token = strtok(line, ",");
            int current_id = atoi(token);
            if (current_id > max_id) {
                max_id = current_id;
            }
        }
        fclose(fptr);
    }
    printf("%d", max_id);

    return max_id;
}


