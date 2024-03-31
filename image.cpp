#include "image.h"

Image::Image(QString filePath)
{
    path = filePath ;
}


Image::Image(QString filePath, int w, int h){
    path = filePath ;
    width = w ;
    height = h ;
}

Image::~Image(){

}

int  Image::getWidth(void){return this->width ;}
void Image::getWidth(int w){this->width = w ;}

int  Image::getHeight(void){return this->height ;}
void Image::getHeight(int h){this->height = h ;}
