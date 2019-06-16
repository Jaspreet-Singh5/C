#include <stdio.h>
#include <stdlib.h>
#include <string.h>

  /* student structure */
  struct student {
        char name[32];
        int age, rollNo;
        int m1, m2, m3;
        float average;
  };

  main() 
  {
        struct student s1;
        int i, n, m1, m2, m3, age, flag, rollNo;
        char name[32];
        float average;
        FILE *fp;

        /* open the given input file in write mode  */
        fp = fopen("record.txt", "a");

        /* get the number of students from the user */
        printf("Enter the number of students:");
        scanf("%d", &n);

        /* get student information from user and write it to a file */
        for (i = 0; i < n; i++) {
                printf("\nEnter student %d details:\n", i + 1);
                getchar();
                printf("Name: ");
                fgets(name, 32, stdin);
                name[strlen(name) - 1] = '\0';
                printf("Roll Number: ");
                scanf("%d", &rollNo);
                printf("Age: ");
                scanf("%d", &age);
                printf("Mark1, Mark2, Mark3:");
                scanf("%d%d%d", &m1, &m2, &m3);
                average = (1.0 * (m1 + m2 + m3)) / 3;

                /* writing student information to a file  */
                fprintf(fp, "%d %s %d %d %d %d %f\n",
                        rollNo, name, age, m1, m2, m3, average);
        }
        /* closing the opened file */
        fclose(fp);

        /* opening the input file in read mode */
        fp = fopen("record.txt", "r");

        /*
         * fetches the desired student record from
         * file and displays it to the user 
         */
        while (1) {
                printf("\nEnter the desired student roll number:");
                scanf("%d", &rollNo);
                flag = 0;
                while (!feof(fp)) {
                		fflush(stdin);
                        fscanf(fp, "%d %s %d %d %d %d %f", &s1.rollNo,
                                s1.name, &s1.age, &s1.m1, &s1.m2, 
                                              &s1.m3, &s1.average);
                        if (s1.rollNo == rollNo) {
                                printf("Details of %s:\n", s1.name);
                                printf("RollNo: %d\n", s1.rollNo);
                                printf("Age: %d\n", s1.age);
                                printf("Mark1: %d\n", s1.m1);
                                printf("Mark2: %d\n", s1.m2);
                                printf("Mark3: %d\n", s1.m3);
                                printf("Average: %f\n", s1.average);
                                flag = 1;
                                break;
                        }
                }

                if (!flag) {
                        printf("Record Not Found!!\n");
                }

                /* rewinding the file pointer to the start of file */
                rewind(fp);
                printf("Do you want to continue(1/0):");
                scanf("%d", &flag);

                if (!flag)
                        break;
        }

        /* closing the file */
        fclose(fp);
        return(0);
  }
