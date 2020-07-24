#include <stdio.h> 
#include <dirent.h> 
#include <stdlib.h> 
   
int main(void) 
{ 
    struct dirent *de;  // Pointer for directory entry 
  	int counter1 = 0;
    // opendir() returns a pointer of DIR type.  
    DIR *dr = opendir("."); 
  
    if (dr == NULL)  // opendir returns NULL if couldn't open directory 
    { 
        printf("Could not open current directory" ); 
        return 0; 
    } 
  
    // Refer http://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html 
    // for readdir() 
   	
    
     	  
      
    
      FILE      *ptrFile = fopen( "index.html", "w"); 
 	int        i; 
 		 
      fprintf( ptrFile, "<!DOCTYPE html><html><head><title>Galeri</title></head><style> html, body, #container {margin: 0;width: 100%%;height: 90%%;}</style><link rel='stylesheet' href='https://cdn.jsdelivr.net/npm/photo-sphere-viewer@4/dist/photo-sphere-viewer.min.css'/><script src='https://cdn.jsdelivr.net/npm/three/build/three.min.js'></script><script src='https://cdn.jsdelivr.net/npm/uevent@2/browser.min.js'></script><script src='https://cdn.jsdelivr.net/npm/photo-sphere-viewer@4/dist/photo-sphere-viewer.min.js'></script><body><div id='container'></div>"); 

 while ((de = readdir(dr)) != NULL){
  	
	if(strstr(de->d_name, ".png") || strstr(de->d_name, ".jpg") || strstr(de->d_name, ".PNG") || strstr(de->d_name, ".jpeg") != NULL) {
    printf("Dosya %s\n", de->d_name); 
    fprintf( ptrFile, "<p>%s </p>\n", de->d_name); 
    fprintf( ptrFile,"<button onclick='resimfunc%d();'>Resim</button>",counter1);
    printf("%d . button icin buton elementi olusturuldu \n",counter1+1);
    counter1++;
	}
}
counter1 = 0;

fprintf( ptrFile,"</body> <script>");
//second loop
printf("ikinci loop\n");

 rewinddir(dr);
 	 while ((de = readdir(dr)) != NULL){
  
    
    	
	if(strstr(de->d_name, ".png") || strstr(de->d_name, ".jpg") || strstr(de->d_name, ".PNG") || strstr(de->d_name, ".jpeg") != NULL) {
    printf("Dosya %s\n", de->d_name); 
    
    fprintf( ptrFile," var resimVar%d = '%s';",counter1,de->d_name);
    printf("%d . resim icin buton javascript degiskeni olusturuldu \n",counter1+1);
    counter1++;
	}
} 
int sayac = counter1;
int c=0;
fprintf(ptrFile,"var div = document.getElementById('container');var PSV = new PhotoSphereViewer.Viewer({panorama: resimVar0,container: div,defaultLat:    0.2,}); ");
  
for(c;c<sayac;c++){
	
	fprintf(ptrFile,"function resimfunc%d(){PSV.setPanorama(resimVar%d).then(() => alert('Tamamlandi'));}",c,c);
	printf("fonksiyon %d olusturuldu\n",c+1);
}
  
  fprintf( ptrFile, "</script></html>"); 
  fclose( ptrFile ); 
  
   closedir(dr);   
printf("\n\n\tpress enter to continue... \n cagricibuk - 2020 \n");
getch();
    return 0; 
} 
