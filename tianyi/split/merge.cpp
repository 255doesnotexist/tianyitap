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

int main(){
	freopen("output.json","w",stdout);
	printf("{\n");
	for(int i=0;i<32;++i){
		int f_size=0; unsigned char *mp3=read_all((tostr(i)+".mp3").c_str(),f_size);
		char *r=(char*)b64_encode(mp3,f_size);
		printf("\"%d.mp3\":\"data:audio/mp3;base64,%s\"",i,r);
		free(r); delete[] mp3;
		if(i!=31) printf(",\n");
	}printf("\n}");
	return 0;
}
