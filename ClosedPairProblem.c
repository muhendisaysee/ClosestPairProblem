#include<stdio.h>
#include<math.h> 
#include<stdlib.h>
#define FLT_MAX 3.40282347E+38F

struct Nokta {
    int x, y;

};
/*----------------------------------------------------------------------------------*/
float minumum_uzaklik(float x, float y)  
{  
	if(x<y){
		return x;
	}  else 
		return y;
}  
/*----------------------------------------------------------------------------------*/
int nokta_sayisi(){
	FILE *fptr;
	int num=0;
	struct Nokta deneme;
	  (fptr = fopen("C:\\Users\\hp\\Desktop\\Input.txt","rb"));
       while(!feof(fptr)){
       	fscanf(fptr,"%d",&deneme.x);
       	num++;
	   }
	   return num;
}
/*---------------------------------------------------------------------------------*/
void y_sirala(int n,struct Nokta siralanacak[n]){
	int i,j;
	struct Nokta tmp;
	for(i=1;i<n;i++){
		for(j=0;j<n-1;j++){
		if(siralanacak[j].x==siralanacak[j+1].x &&siralanacak[j].y>siralanacak[j+1].y){
				  tmp=siralanacak[j];
				  siralanacak[j]=siralanacak[j+1];
				  siralanacak[j+1]=tmp;
			}
		}
	}
}
/*----------------------------------------------------------------------------------*/
float oklid(struct Nokta nokta1,struct Nokta nokta2){
	struct Nokta en_kucuk[10];
	int count=0;
	float hesapla=sqrt(((nokta1.x-nokta2.x)*(nokta1.x-nokta2.x))+((nokta1.y-nokta2.y)*(nokta1.y-nokta2.y)));
	printf("-------------------------------------------------------");
		printf("\nEn son X1 x: %d\n",nokta1.x);
		printf("\nEn son Y1 y: %d\n",nokta1.y);
		printf("\nEn son X2 x: %d\n",nokta2.x);	
		printf("\nEn son Y2 x: %d\n",nokta2.y);
		printf("-------------------------------------------------------");
		
	return hesapla;
}
/*----------------------------------------------------------------------------------*/
void quickSort(int n,struct Nokta koordinatDuzlemi[n],int bas,int son){
   	struct Nokta tmp_point;
   	int i, j, orta;
   if(bas<son){
      orta=bas;
      i=bas;
      j=son;

      while(i<j){
         while(koordinatDuzlemi[i].x<=koordinatDuzlemi[orta].x&&i<son)
            i++;
         while(koordinatDuzlemi[j].x>koordinatDuzlemi[orta].x)
            j--;
         if(i<j){
            tmp_point=koordinatDuzlemi[i];
            koordinatDuzlemi[i]=koordinatDuzlemi[j];
            koordinatDuzlemi[j]=tmp_point;
         }
      }

      tmp_point=koordinatDuzlemi[orta];
      koordinatDuzlemi[orta]=koordinatDuzlemi[j];
      koordinatDuzlemi[j]=tmp_point;
      quickSort(n,koordinatDuzlemi,bas,j-1);
      quickSort(n,koordinatDuzlemi,j+1,son);

   }
}
/*----------------------------------------------------------------------------------*/
float en_yakin_nokta(struct Nokta serit[], int size, float d)  
{
	int x1=0,x2=0,y1=0,y2=0;
    float min = d; 
    quickSort(size,serit,0,sizeof(serit));
  	int i,j;
	  	i=0;
		while(i<size/2){
			j=i+1;	
			while(j<size/2 && (serit[j].y -serit[i].y) < min){
					
				if(oklid(serit[i],serit[j]) < min){
				
					min=oklid(serit[i],serit[j]);
					x1=serit[i].x;
				}
				j++;
			}
			i++;
		}
    return min;  
}
/*-----------------------------------------------------------------------------------*/
float brute_force(int n,struct Nokta koordinatDuzlemi[n]){
	
     	struct Nokta koorSonuc1;
		struct Nokta koorSonuc2;
		float eski=FLT_MAX;
		float yeni=0.0;
		int i,j;
		//	yeni=sqrt(((koor[i].x-koor[j].x)*(koor[i].x-koor[j].x))+((koor[i].y-koor[j].y)*(koor[i].y-koor[j].y)));
		int count=1;
		for(i=0;i<n;++i){
			for(j=i+1;j<n;++j){
				yeni=oklid(koordinatDuzlemi[i],koordinatDuzlemi[j]);
				if(yeni==eski){
					count++;
					if(count==2){
						printf("\nBUTUN NOKTALAR BIRBIRINE ESIT UZAKLIKTA!!\n");
					}
				}
				if(yeni<eski){
					eski=yeni;
					koorSonuc1.x=koordinatDuzlemi[i].x;
					koorSonuc1.y=koordinatDuzlemi[i].y;
					koorSonuc2.x=koordinatDuzlemi[j].x;
					koorSonuc2.y=koordinatDuzlemi[j].y;
				}
				}
			
		}
		
		if(count!=2){
			printf("\n--------------------------------------------\n");
			printf("\nBU IKI NOKTA ARASINDAKI UZAKLIK : %f\n",yeni);
			printf("\n1.Nokta X : %d",koorSonuc1.x);
			printf("\n1.Nokta Y : %d",koorSonuc1.y);
			printf("\n2.Nokta X : %d",koorSonuc2.x);
			printf("\n2.Nokta Y : %d",koorSonuc2.y);
	
			printf("\n--------------------------------------------\n");
}
	return yeni;
}
/*-----------------------------------------------------------------------------*/
float closest_pair(struct Nokta koordinat[],int n){
float dltmp=FLT_MAX,drtmp=FLT_MAX,dl=0,dr=0;
	if (n <= 3)  
         return brute_force(n,koordinat);
  
    		int orta=n/2;
    		struct Nokta orta_nokta=koordinat[orta];
    		printf("\nOrta nokta x : %d\n",koordinat[orta].x);
    		printf("Ortanin indisi : %d\n",orta);
    		printf("\nOrta nokta y : %d\n",koordinat[orta].y);
    		if(dltmp>dl){
			     dl=closest_pair(koordinat,orta+1);
				 dltmp=dl;
				
	}
			if(drtmp>dr){
			
				dr=closest_pair(koordinat+orta,n-orta);
				drtmp=dr;
						
		}
			 printf("\ndltmp : %f \n",dltmp);
			printf("\ndrtmp : %f \n",drtmp);
			float d=minumum_uzaklik(dltmp,drtmp);
			struct Nokta serit[n];
		int count=0,i;
		int uzaklik;
		i=0;
		while(i<n){
			uzaklik=koordinat[i].x -orta_nokta.x;
			if(uzaklik < d){
				serit[count]=koordinat[i];
				count++;
			}
			i++;
		
		return minumum_uzaklik(d , en_yakin_nokta(serit,count,d));
		}
}
/*-------------------------------------------------------------------*/
int main() {

    printf("   \t\t\t--------------ALGORITMA ANALIZI BIRINCI ODEVIM------------      \n\n");
    /*---------------------------------------------------------------------------------*/
    int n, i, deger, j,m;
    /*--------------------------------------------------------------------------------*/
    n=nokta_sayisi();
  	n=n/2;
  	printf("\n n: %d\n",n);
    struct Nokta koordinatDuzlemi[n]; //Noktalarýn tutulduðu struct yapýsý.
    struct Nokta deneme;
	int dizi[n*2];
    int num=0;
    FILE *fptr;
    /*---------------------------------------------------------------------------------*/
   (fptr = fopen("C:\\Users\\hp\\Desktop\\Input.txt","rb"));
       while(!feof(fptr)){
       	fscanf(fptr,"%d",&deneme.x);
       		printf("%d",deneme.y);
      	dizi[num]=deneme.x;
       	num++;
	   }
	/*----------------------------------------------------------------------------------*/
	for(i=0;i<n*2;i++){

		if(i%2==0){
			koordinatDuzlemi[i/2].x=dizi[i];
		}else if(i%2!=0){
			koordinatDuzlemi[i/2].y=dizi[i];
		}
	}
	/*----------------------------------------------------------------------------------*/
	for(i=0;i<n;i++){
		printf("Sonuclar");
		printf("\nx : %d",koordinatDuzlemi[i].x);
		printf("y : %d\n",koordinatDuzlemi[i].y);
	}
  	fclose(fptr);
    /*----------------------------------------------------------------------------------*/
    for(i=0;i<n;i++){
    	printf("-----------------");
    		printf("\nx : %d\n",koordinatDuzlemi[i].x);
    		printf("y : %d\n",koordinatDuzlemi[i].y);
	}
    /*----------------------------------------------------------------------------------*/
   
    if(n==2 || n==3){
    	brute_force(n,koordinatDuzlemi);
	}
     else if (n > 3) {
  	int deger2;
  	quickSort((n+n),koordinatDuzlemi,0,n-1);
  	y_sirala((n+n),koordinatDuzlemi);
  	/*----------------------------------------------------------------------------------*/
    for(i=0;i<n;i++){
    	printf("--------**********---------");
    		printf("\nx : %d\n",koordinatDuzlemi[i].x);
    		printf("y : %d\n",koordinatDuzlemi[i].y);
	}
	/*----------------------------------------------------------------------------------*/
    	float deger=closest_pair(koordinatDuzlemi,n);
    /*-----------------------------------------------------------------------------------*/
    	printf("SONUC : %f",deger);
	}
	/*-----------------------------------------------------------------------------------*/
	 else {
        printf("Ikiden küçük nokta giremezsiniz! ");
    }
     /*----------------------------------------------------------------------------------*/
}
