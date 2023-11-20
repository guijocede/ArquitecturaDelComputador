#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
#define TAM_CACHE 4

int main(){
	
	int i,j;
	int numero, tam;
	int c1,c2;
	int a,b,c,d;
	int line[100];
	int mem[TAM_CACHE];
	
	mem[0] = -1;
	
	fstream archivo;
	
	archivo.open("secuencia.txt",ios::in);
    
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
	
	archivo >> numero;
	
	while(!archivo.eof()){
	
	line[0] = numero;
	i = 1;
	
	while((archivo >> numero)&&line[i-1]!=-1){
    line[i] = numero;
    i++;
	}
	
	tam = i-1;
	
	
	
	
	cout<<"Correspondencia directa: ";
	
	for(j=0;j<TAM_CACHE;j++){
		
		mem[j] = -1;
		
	}
	
	for(i=0;i<tam;i++){
		cout<<line[i]<<" ";
	}
	
	cout<<"\n";
	
	i = 0;
	
	while(line[i]!=-1){
		
		if(line[i]==mem[line[i]%4]){
			cout<<"acierto\n";
		}else{
			
			cout<<"fallo\n";
			mem[line[i]%4] = line[i];
			
		}
		
		i++;
	}
	
	
	
	cout<<"\nAsociativa por conjuntos: ";
	
	for(i=0;i<tam;i++){
		cout<<line[i]<<" ";
	}
	
	cout<<"\n";
	
	for(j=0;j<TAM_CACHE;j++){
		
		mem[j] = -1;
		
	}
	
	i = 0;
	c1 =0;
	c2 =2;
	
	while(line[i]!=-1){
		
		if(line[i]%2==0){
			
			if(line[i]==mem[0]){
			
				cout<<"acierto\n";
				c1 = 1;
			
			}else if(line[i]==mem[1]){
				
				cout<<"acierto\n";
				c1 = 0;
				
			}else{
				
				cout<<"fallo\n";
				mem[c1] = line[i];
				
				if(c1==1){
					c1=0;
				} else{
					c1=1;
				}
				
			}
			
		}else{
			
			if(line[i]==mem[2]){
			
				cout<<"acierto\n";
				c2 = 3;
			
			}else if(line[i]==mem[3]){
				
				cout<<"acierto\n";
				c2 = 2;
				
			}else{
				
				cout<<"fallo\n";
				mem[c2] = line[i];
				if(c2==2){
					c2=3;
				}else{
					c1=2;
				}
				
			}
			
		}
		
		i++;
	}
	
	cout<<"\nCompletamente asociativa: ";
	
	for(i=0;i<tam;i++){
		cout<<line[i]<<" ";
	}
	
	cout<<"\n";
	
	for(j=0;j<TAM_CACHE;j++){
		
		mem[j] = -1;
		
	}
	
	i = 0;
	
	a = 4;
	b = 3;
	c = 2;
	d = 1;
	
	while(line[i]!=-1){
		
		if(line[i]==mem[0]){
			
			cout<<"acierto\n";
			if(a==4){
				
				a=1;
				b++;
				c++;
				d++;
				
			}else if(a!=1){
				
				a=1;
				
				if(b==4){
					
					c++;
					d++;
					
				}else if (c==4){
					
					b++;
					d++;
					
				}else {
					
					b++;
					c++;
					
				}
				
			}
			
			
		}else if(line[i]==mem[1]){
			
			cout<<"acierto\n";
			if(b==4){
				
				b=1;
				a++;
				c++;
				d++;
				
			}else if(b!=1){
				
				b=1;
				
				if(a==4){
					
					c++;
					d++;
					
				}else if (c==4){
					
					a++;
					d++;
					
				}else{
					
					a++;
					c++;
					
				}
				
			}
			
		}else if(line[i]==mem[2]){
			
			cout<<"acierto\n";
			if(c==4){
				
				c=1;
				a++;
				b++;
				d++;
				
			}else if(c!=1){
				
				c=1;
				
				if(a==4){
					
					b++;
					d++;
					
				}else if (b==4){
					
					a++;
					d++;
					
				}else {
					
					a++;
					b++;
					
				}
				
			}
			
			
		}else if(line[i]==mem[3]){
			
			cout<<"acierto\n";
			if(d==4){
				
				d=1;
				a++;
				b++;
				c++;
				
			}else if(d!=1){
				
				d=1;
				
				if(a==4){
					
					b++;
					c++;
					
				}else if (b==4){
					
					a++;
					c++;
					
				}else{
					
					a++;
					b++;
					
				}
				
			}
			
		}else{
			
			cout<<"fallo\n";
			
			if(a==4){
				
				mem[0] = line[i];
				a = 1 ;
				b++;
				c++;
				d++;
				
			}else if(b==4){
				
				mem[1] = line[i];
				b = 1 ;
				a++;
				c++;
				d++;
				
			}else if(c==4){
				
				mem[2] = line[i];
				c = 1 ;
				a++;
				b++;
				d++;
				
			}else{
				
				mem[3] = line[i];
				d = 1 ;
				a++;
				b++;
				c++;
				
			}
			
		}
		
		
		
		i++;
	}
	
	cout<<"\n";
	
	}
	
	
	archivo.close();
	
	system("pause");
	return 0;
}
