#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<stdarg.h>
#include<time.h>
#include<signal.h>
#include<sys/stat.h>
#define N 100
#define RWXRWXRWX (S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP|S_IWGRP|S_IXGRP|S_IROTH|S_IWOTH|S_IXOTH)

typedef struct {int num;} NUM;
char filec[N],filename[N],forcmp[N];
sigset_t set1,set2;
char str[] = "#include%c%cmyhead.h%c%c#define%cN%c100%c#define%cRWXRWXRWX%c(S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP|S_IWGRP|S_IXGRP|S_IROTH|S_IWOTH|S_IXOTH)%c%ctypedef%cstruct%c{int%cnum;}%cNUM;%cchar%cfilec[N],filename[N],forcmp[N];%csigset_t%cset1,set2;%cchar str[] = %c%s%c;%c%cvoid%cInitial();%cint%cJudge();%cvoid%cRandStr(char%c*,%cint);%cvoid%cSignal_Catch(int);%c%cint%cmain()%c{%c%cInitial();%c%cint%ci;%c%csigemptyset(&set1);%c%csigemptyset(&set2);%c%csigaddset(&set1,SIGINT);%c%csigprocmask(SIG_SETMASK,%c&set2,%cNULL);%c%csigprocmask(SIG_UNBLOCK,%c&set1,%c&set2);%c%csignal(SIGINT,Signal_Catch);%c%c%c%c%cprintf(%cpid:%c%cd%cppid:%c%cd%cn%c,getpid(),%cgetppid());%c%c%cpause();%c%c/*%c%cfor(i%c=%c0;;%ci++)%c%c{%c%c%cif(i%c==%c150000000)%c%c%c{%c%c%c%ci%c=%c0;%c%c%c%cputs(%c%cn^_^%cI%cm%crunning...%c);%c%c%c%cprintf(%cpid:%c%cd%cppid:%c%cd%cn%c,getpid(),%cgetppid());%c%c%c}%c%c}%c%c*/%c%creturn%c0;%c}%c%cvoid%cInitial()%c{%c%cFILE%c*fp;%c%c%cif((fp%c=%cfopen(%ccount.txt%c,%cr%c))%c==%cNULL)%c%c{%c%c%cNUM%ca;%c%c%ca.num%c=%c10;%c%c%cfp%c=%cfopen(%ccount.txt%c,%cw%c);%c%c%cfwrite(&a,sizeof(NUM),1,fp);%c%c%cfclose(fp);%c%c%c}%celse%cfclose(fp);%c}%c%cint%cJudge()%c{%c%cNUM%ca;%c%cFILE%c*fp;%c%cif((fp%c=%cfopen(%ccount.txt%c,%cr+%c))%c!=%cNULL)%c%c{%c%c%cfread(&a,sizeof(NUM),1,fp);%c%c%c%cif(a.num%c==%c0)%c%c%c{%c%c%c%cfclose(fp);%c%c%c%cexit%c(0);%c%c%c}%c%c%cprintf(%ccount.txt:%c%cd%cn%c,a.num--);%c%c%cfseek(fp,-1*sizeof(NUM),SEEK_CUR);%c%c%cfwrite(&a,sizeof(NUM),1,fp);%c%c%c%cfclose(fp);%c%c%creturn%c1;%c%c}%c}%c%cvoid%cRandStr(char%c*name,%cint%clen)%c{%c%cint%ci;%c%csrand((unsigned)time(NULL));%c%cfor(i%c=%c0;%ci%c<%clen;%ci++)%c%c{%c%c%cname[i]%c=%c%ca%c%c+%c(rand()%c26);%c%c}%c%cname[len]%c=%c%c%c0%c;%c%c}%c%cvoid%cSignal_Catch(int%csignal_num)%c{%c%c//if(!Judge())%creturn;%c%cprintf(%ccatch%csignal%c%cd%cn%c,signal_num);%c%c%cpid_t%cpid;%c%c%cRandStr(filename,6);%c%c%csprintf(filec,%c%cs.c%c,filename);%c%c%cprintf(%cP:%cwrite%cstr%cto%cfile:%c%cs%cn%c,filec);%c%cFILE%c*fp%c=%cfopen(filec,%cw%c);%c%cfprintf(fp,str,32,34,34,10,32,32,10,32,32,10,10,32,32,32,32,10,32,10,32,10,34,str,34,10,10,32,10,32,10,32,32,32,10,32,10,10,32,10,10,9,10,9,32,10,9,10,9,10,9,10,9,32,32,10,9,32,32,10,9,10,9,10,10,9,34,32,37,32,32,37,92,34,32,10,9,9,10,9,10,9,32,32,32,10,9,10,9,9,32,32,10,9,9,10,9,9,9,32,32,10,9,9,9,34,92,32,39,32,34,10,9,9,9,34,32,37,32,32,37,92,34,32,10,9,9,10,9,10,9,10,9,32,10,10,10,32,10,10,9,32,9,10,9,32,32,34,34,34,34,32,32,10,9,10,9,9,32,10,9,9,32,32,10,9,9,32,32,34,34,34,34,10,9,9,10,9,9,9,10,9,32,32,10,10,10,32,10,10,9,32,10,9,32,10,9,32,32,34,34,34,34,32,32,10,9,10,9,9,9,10,9,9,32,32,10,9,9,10,9,9,9,10,9,9,9,32,10,9,9,10,9,9,34,32,37,92,34,10,9,9,10,9,9,9,10,9,9,10,9,9,32,10,9,10,10,10,32,32,32,32,10,10,9,32,10,9,10,9,32,32,32,32,32,32,10,9,10,9,9,32,32,39,39,32,32,37,10,9,10,9,32,32,39,92,39,9,10,10,10,32,32,10,10,9,9,10,9,34,32,32,37,92,34,10,10,9,32,9,10,9,9,10,9,34,37,34,10,10,9,34,32,32,32,32,32,37,92,34,10,9,32,32,32,34,34,10,9,10,9,10,10,9,32,32,32,32,10,9,10,9,9,34,32,34,10,9,9,10,9,10,9,32,32,32,10,9,10,9,9,34,32,32,37,32,32,37,92,34,32,10,9,9,34,32,32,37,32,32,37,92,34,32,10,9,9,34,32,37,32,32,37,34,10,9,9,10,9,34,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,34,10,9,34,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,34,10,9,34,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,39,32,32,32,32,34,10,9,34,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,34,10,9,34,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,34,10,9,9,10,9,9,10,9,9,34,37,34,10,9,9,10,9,9,10,9,10,9,10,9,10,9,9,34,32,32,32,92,34,10,9,9,34,34,10,9,9,34,32,32,32,32,32,32,34,10,9,9,34,34,10,9,9,34,32,32,37,32,32,37,92,34,32,10,9,9,10,9,9,10,9,9,10,9,10,9,10,10);%c%cfclose(fp);%c%c%cif((pid%c=%cvfork())%c<%c0)%c%c{%c%c%cfprintf(stderr,%cvfork%cerror%c);%c%c%cexit(1);%c%c}%c%celse%cif(pid%c==%c0)%c%c{%c%c%cprintf(%cS:%ccompile%c%cs%cto%c%cs%cn%c,filec,%cfilename);%c%c%cprintf(%cS:%cpid:%c%cd%cppid:%c%cd%cn%c,getpid(),%cgetppid());%c%c%csprintf(forcmp,%cgcc%c%cs%c-o%c%cs%c,filec,filename);%c%c%csystem(forcmp);%c%cputs(%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c#########################%c);%c%cputs(%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c#%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c#%c);%c%cputs(%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c#%c:-)%ci%cm%crunning%cagin%c%c#%c);%c%cputs(%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c#%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c#%c);%c%cputs(%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c#########################%c);%c%c%c//sleep(0.5);%c%c%c//getchar();%c%c%csprintf(forcmp,%c./%cs%c,filename);%c%c%cexecl(forcmp,forcmp,NULL);%c%c%cexit(0);%c%c}%c%celse%c%c{%c%c%cprintf(%cP:%cready%cto%cdie%cn%c);%c%c%cputs(%c**************%c);%c%c%cputs(%c*%c%c%cKilled%c%c%c*%c);%c%c%cputs(%c**************%c);%c%c%cprintf(%cP:%cpid:%c%cd%cppid:%c%cd%cn%c,getpid(),%cgetppid());%c%c%c//kill(getpid(),SIGKILL);%c%c%c//pause();%c%c%cexit(0);%c%c}%c%creturn;%c}%c";

void Initial();
int Judge();
void RandStr(char *, int);
void Signal_Catch(int);

int main()
{
	Initial();
	int i;
	sigemptyset(&set1);
	sigemptyset(&set2);
	sigaddset(&set1,SIGINT);
	sigprocmask(SIG_SETMASK, &set2, NULL);
	sigprocmask(SIG_UNBLOCK, &set1, &set2);

	signal(SIGINT,Signal_Catch);
	
	printf("pid: %d ppid: %d\n",getpid(), getppid());
	pause();
	/*
	for(i = 0;; i++)
	{
		if(i == 150000000)
		{
			i = 0;
			puts("\n^_^ I'm running...");
			printf("pid: %d ppid: %d\n",getpid(), getppid());
		}
	}
	*/
	return 0;
}

void Initial()
{
	FILE *fp;	
	if((fp = fopen("count.txt","r")) == NULL)
	{
		NUM a;
		a.num = 10;
		fp = fopen("count.txt","w");
		fwrite(&a,sizeof(NUM),1,fp);
		fclose(fp);	
	} else fclose(fp);
}

int Judge()
{
	NUM a;
	FILE *fp;
	if((fp = fopen("count.txt","r+")) != NULL)
	{
		fread(&a,sizeof(NUM),1,fp);	
		if(a.num == 0)
		{
			fclose(fp);
			exit (0);		
		}
		printf("count.txt: %d\n",a.num--);
		fseek(fp,-1*sizeof(NUM),SEEK_CUR);
		fwrite(&a,sizeof(NUM),1,fp);	
		fclose(fp);
		return 1;
	}
}

void RandStr(char *name, int len)
{
	int i;
	srand((unsigned)time(NULL));
	for(i = 0; i < len; i++)
	{
		name[i] = 'a' + (rand()%26);
	}
	name[len] = '\0';	
}

void Signal_Catch(int signal_num)
{
	//if(!Judge())	return; 	
	printf("catch signal %d\n",signal_num);

	pid_t pid;	
	RandStr(filename,6);	
	sprintf(filec,"%s.c",filename);

	printf("P: write str to file: %s\n",filec);
	FILE *fp = fopen(filec,"w");
	fprintf(fp,str,32,34,34,10,32,32,10,32,32,10,10,32,32,32,32,10,32,10,32,10,34,str,34,10,10,32,10,32,10,32,32,32,10,32,10,10,32,10,10,9,10,9,32,10,9,10,9,10,9,10,9,32,32,10,9,32,32,10,9,10,9,10,10,9,34,32,37,32,32,37,92,34,32,10,9,9,10,9,10,9,32,32,32,10,9,10,9,9,32,32,10,9,9,10,9,9,9,32,32,10,9,9,9,34,92,32,39,32,34,10,9,9,9,34,32,37,32,32,37,92,34,32,10,9,9,10,9,10,9,10,9,32,10,10,10,32,10,10,9,32,9,10,9,32,32,34,34,34,34,32,32,10,9,10,9,9,32,10,9,9,32,32,10,9,9,32,32,34,34,34,34,10,9,9,10,9,9,9,10,9,32,32,10,10,10,32,10,10,9,32,10,9,32,10,9,32,32,34,34,34,34,32,32,10,9,10,9,9,9,10,9,9,32,32,10,9,9,10,9,9,9,10,9,9,9,32,10,9,9,10,9,9,34,32,37,92,34,10,9,9,10,9,9,9,10,9,9,10,9,9,32,10,9,10,10,10,32,32,32,32,10,10,9,32,10,9,10,9,32,32,32,32,32,32,10,9,10,9,9,32,32,39,39,32,32,37,10,9,10,9,32,32,39,92,39,9,10,10,10,32,32,10,10,9,9,10,9,34,32,32,37,92,34,10,10,9,32,9,10,9,9,10,9,34,37,34,10,10,9,34,32,32,32,32,32,37,92,34,10,9,32,32,32,34,34,10,9,10,9,10,10,9,32,32,32,32,10,9,10,9,9,34,32,34,10,9,9,10,9,10,9,32,32,32,10,9,10,9,9,34,32,32,37,32,32,37,92,34,32,10,9,9,34,32,32,37,32,32,37,92,34,32,10,9,9,34,32,37,32,32,37,34,10,9,9,10,9,34,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,34,10,9,34,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,34,10,9,34,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,39,32,32,32,32,34,10,9,34,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,34,10,9,34,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,34,10,9,9,10,9,9,10,9,9,34,37,34,10,9,9,10,9,9,10,9,10,9,10,9,10,9,9,34,32,32,32,92,34,10,9,9,34,34,10,9,9,34,32,32,32,32,32,32,34,10,9,9,34,34,10,9,9,34,32,32,37,32,32,37,92,34,32,10,9,9,10,9,9,10,9,9,10,9,10,9,10,10);
	fclose(fp);

	if((pid = vfork()) < 0)
	{
		fprintf(stderr,"vfork error");
		exit(1);
	}
	else if(pid == 0)
	{
		printf("S: compile %s to %s\n",filec, filename);
		printf("S: pid: %d ppid: %d\n",getpid(), getppid());
		sprintf(forcmp,"gcc %s -o %s",filec,filename);
		system(forcmp);
	puts("                  #########################");
	puts("                  #                       #");
	puts("                  # :-) i'm running agin  #");
	puts("                  #                       #");
	puts("                  #########################");
		//sleep(0.5);
		//getchar();
		sprintf(forcmp,"./%s",filename);
		execl(forcmp,forcmp,NULL);
		exit(0);
	}
	else
	{
		printf("P: ready to die\n");
		puts("**************");
		puts("*   Killed   *");
		puts("**************");
		printf("P: pid: %d ppid: %d\n",getpid(), getppid());
		//kill(getpid(),SIGKILL);
		//pause();
		exit(0);
	}
	return;
}
