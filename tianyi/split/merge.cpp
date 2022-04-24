#include <bits/stdc++.h>
#include "b64/b64.h"
#include "b64/decode.c"
#include "b64/encode.c"
#include "b64/buffer.c"

using namespace std;

unsigned char *read_all(const char *filename,int &size){
//	static unsigned char buf[1024];
	FILE *fp=fopen(filename,"rb");
	fseek(fp,0L,SEEK_END);
	int filesize=ftell(fp);
	fseek(fp,0L,SEEK_SET);
	unsigned char *ret=new unsigned char[(filesize+4)*sizeof(unsigned char)];
    memset(ret,0,sizeof(char)*filesize);
	fread(ret,sizeof(unsigned char),filesize,fp);
    fclose(fp); size=filesize*sizeof(unsigned char);
    return ret;
} 

string tostr(int x){
	ostringstream os; os<<x; return os.str();
}

const int id[]={0,1,10,11,12,13,14,15,16,17,18,19,2,20,21,22,23,24,25,26,27,28,29,3,30,31,4,5,6,7,8,9};

int main(){
	freopen("output.json","w",stdout);
	printf("{\n");
	for(int j=0;j<32;++j){
		int i=id[j];
		int f_size=0; unsigned char *mp3=read_all((tostr(i)+".mp3").c_str(),f_size);
		char *r=(char*)b64_encode(mp3,f_size);
		printf("\"%d.mp3\":\"data:audio/mp3;base64,%s\"",i,r);
		free(r); delete[] mp3;
		if(j!=31) printf(",\n");
	}printf("\n}");
	return 0;
}
