typedef unsigned short u16;

int tsize, dsize, ksectors, i, NSEC=1;


int prints(char *s){ while(*s) putc(*s++);}

int getsector(u16 sector){
	readfd(sector/36, ((sector)%36)/18, (((sector)%36)%18));}

/*
void tmp(){
	int i = 1; 
	int j = 2;
	i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;
	i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;
i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;
i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;
i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;
i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;
i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;
i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;i++;j++;
}
*/

main(){
	int i = 0;
	

	prints("booting MTx\n\r");
	tsize = *(int *)(512 + 2);
	dsize = *(int *)(512 + 4);
	ksectors = ((tsize << 4) + dsize + 511)/512;
	setes(0x1000);
	for (i = 1; i <= ksectors + 1; i++){
		getsector(i); inces(); putc('.');
	}
	prints("\n\rready to go?");
	getc();
}
