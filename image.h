#ifndef IMAGE_H
#define IMAGE_H

/* Contient toutes les infos nécessaires pour afficher une image :
*  Résolution, et chemin du fichier sur le disque pour l'instant.
*  Par défaut, image de 640x480s
*/
#include <QString>

class Image
{

private :
    QString path ;
    int width = 640 ;
    int height = 480 ;

public:
    Image(QString filePath) ;
    Image(QString filePath, int width, int height) ;
    ~Image() ;

    int  getWidth(void) ;
    void getWidth(int w) ;

    int  getHeight(void) ;
    void getHeight(int h) ;
};

#endif // IMAGE_H
