#include <windows.h>
#include <gl/glut.h>

// Função callback chamada para fazer o desenho
void DesenhaLabirinto(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
                   
    // Limpa a janela de visualização com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT);
  
    // Desenha um quadrado preenchido com a cor corrente
    glBegin(GL_LINE_STRIP);
    	// Especifica que a cor corrente é preta
        glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2i(100,50);
		glVertex2i(100,150);
		glVertex2i(50,150);
		glVertex2i(50,200);
		glVertex2i(150,200); 
		glVertex2i(150,100);  
		glVertex2i(250,100);  
		glVertex2i(250,250);
		glVertex2i(300,250);        
    glEnd();
	 
	glBegin(GL_LINE_STRIP);
		// Especifica que a cor corrente é preta
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2i(75,50);
		glVertex2i(75,125);  
		glVertex2i(25,125); 
		glVertex2i(25,225);
		glVertex2i(175,225);
		glVertex2i(175,125); 
		glVertex2i(225,125); 
		glVertex2i(225,275); 
		glVertex2i(300,275);       
    glEnd();
    DesenhaObjeto();
    // Executa os comandos OpenGL
    glFlush();
}

void DesenhaObjeto(void)
{
	glBegin(GL_TRIANGLES);
				
	glEnd();
}

// Inicializa parâmetros de rendering
void Inicializa (void)
{   
    // Define a cor de fundo da janela de visualização como branca
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
                   // Evita a divisao por zero
                   if(h == 0) h = 1;
                           
                   // Especifica as dimensões da Viewport
                   glViewport(0, 0, w, h);

                   // Inicializa o sistema de coordenadas
                   glMatrixMode(GL_PROJECTION);
                   glLoadIdentity();

                   // Estabelece a janela de seleção (left, right, bottom, top)
                   if (w <= h) 
                           gluOrtho2D (0.0f, 300.0f, 0.0f, 300.0f*h/w);
                   else 
                           gluOrtho2D (0.0f, 300.0f*w/h, 0.0f, 300.0f);
}

// Programa Principal 
int main(void)
{
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
     glutInitWindowSize(400,350);
     glutInitWindowPosition(10,10);
     glutCreateWindow("Quadrado");
     glutDisplayFunc(Desenha);
	 glutReshapeFunc(AlteraTamanhoJanela);
     Inicializa();
     glutMainLoop();
}
