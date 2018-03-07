#include <stdio.h>
#include "efs.h"

int main(int argc, char** argv)
{
	EmbeddedFileSystem efs;
	EmbeddedFile file;	
	unsigned short e;
	unsigned short bufsize;
	char *buf;
	FILE *localfile;
	
	if(argc<4){
		fprintf(stderr,"Argument error : cpo <fs> <file_read> <local_write> [bufsize]\n");
		exit(-1);
	}

	if(argc==5)
		bufsize=atoi(argv[4]);
	else
		bufsize=4096;
	buf=malloc(bufsize);
	
	if(efs_init(&efs,argv[1])!=0){
		printf("Could not open filesystem.\n");
		return(-1);
	}
	
	if(file_fopen(&file,&efs.myFs,argv[2],'r')!=0){
		printf("Could not open file.\n");
		return(-2);
	}

	if(!(localfile=fopen(argv[3],"w"))){
		printf("Could not open local file.\n");
		return(-3);
	}
	
	while((e=file_read(&file,bufsize,buf))){
		fwrite(buf,1,e,localfile);
	}

	file_fclose(&file);
	fclose(localfile);
	fs_umount(&(efs.myFs));

	return(0);
}
