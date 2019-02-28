#include <windows.h>
#include <gl/glut.h>

float posicaoXObjeto = 0;
float posicaoYObjeto = 0;

void DesenhaLabirinto(void)
{
    glBegin(GL_LINE_STRIP);
    	// Especifica que a cor corrente é preta
        glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(100.0,50.0);
		glVertex2f(100.0,150.0);
		glVertex2f(50.0,150.0);
		glVertex2f(50.0,200.0);
		glVertex2f(150.0,200.0); 
		glVertex2f(150.0,100.0);  
		glVertex2f(250.0,100.0);  
		glVertex2f(250.0,250.0);
		glVertex2f(300.0,250.0);        
    glEnd();
	 
	glBegin(GL_LINE_STRIP);
		// Especifica que a cor corrente é preta
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(75,50);
		glVertex2f(75,125);  
		glVertex2f(25,125); 
		glVertex2f(25,225);
		glVertex2f(175,225);
		glVertex2f(175,125); 
		glVertex2f(225,125); 
		glVertex2f(225,275); 
		glVertex2f(300,275);       
    glEnd();
}

void DesenhaObjeto(void)
{
	glTranslatef(posicaoXObjeto, posicaoYObjeto, 0.0f);
	glBegin(GL_TRIANGLES);
		// Especifica que a cor corrente é preta
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(81.25,50.0);
		glVertex2f(93.75,50.0);
		glVertex2f(87.5,60.82);
	glEnd();
}

void Desenha(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
                   
    // Limpa a janela de visualização com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT);
    DesenhaLabirinto();
  	DesenhaObjeto();
  	
    // Executa os comandos OpenGL
    glFlush();
}

void MovimentaObjeto(int key, int x, int y)
{
	switch (key) {
            case GLUT_KEY_LEFT: 
            	posicaoXObjeto--;
            	break;
            case GLUT_KEY_UP:
            	posicaoYObjeto++;
            	break;
            case GLUT_KEY_RIGHT:
            	posicaoXObjeto++;
                break;
            case GLUT_KEY_DOWN:
            	posicaoYObjeto--;
           		break;
    }
    glutPostRedisplay();
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
     glutCreateWindow("Labirinto");
     glutDisplayFunc(Desenha);
	 glutReshapeFunc(AlteraTamanhoJanela);
	 glutSpecialFunc(MovimentaObjeto);
     Inicializa();
     glutMainLoop();
}
