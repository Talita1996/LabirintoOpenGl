#include <windows.h>
#include <gl/glut.h>
#include <string.h>

float posicaoXObjeto = 0;
float posicaoYObjeto = 0;
int vidas = 4;
float cores[15] = {0.0f, 0.15f, 0.2f, 0.25f, 0.3f, 0.4, 0.5f, 0.6f, 0.65f, 0.7f, 0.75f, 0.8f, 0.9f, 0.95f, 1.0f};
int a = 0;
int b = 0;
int c = 14;

int VerificaPosicao(float x, float y);
void RenderString(float x, float y,  void *font, const char* string);

void DesenhaLabirinto(void)
{
    glBegin(GL_LINE_STRIP);
        glColor3f(cores[a], cores[b], cores[b]);
        glVertex2f(75,50);
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
		glColor3f(cores[a], cores[b], cores[b]);
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
	char novoId[9];
	
	snprintf(novoId, 8, "Vidas: %d", vidas);
	RenderString(10.0f, 275.0f, GLUT_BITMAP_HELVETICA_10, novoId);
	glTranslatef(posicaoXObjeto, posicaoYObjeto, 0.0f);
	
	glBegin(GL_TRIANGLES);
        glColor3f(cores[c], cores[b], cores[a]);
		// Especifica que a cor corrente é preta
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(81.25,51.0);
		glVertex2f(93.75,51.0);
		glVertex2f(87.5,60.82);
	glEnd();
}

void GameOver()
{
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	RenderString(110.0f, 150.0f, GLUT_BITMAP_HELVETICA_18, "Voce perdeu :(");
	RenderString(90.0f, 130.0f, GLUT_BITMAP_HELVETICA_10, "Pressione qualquer tecla para reiniciar");
	posicaoXObjeto = 0;
	posicaoYObjeto = 0;
	vidas = 4;
	glFlush();	
}

void PerdeVida()
{
	posicaoXObjeto = 0;
	posicaoYObjeto = 0;
	vidas--;
	if(!vidas)
		GameOver();
		return;
	glutPostRedisplay();
	return;	
}

void RenderString(float x, float y,  void *font, const char* string)
{  
	int aux = 0;
	int n = strlen(string);
	
	glColor3f(0.0f, 0.0f, 0.0f); 
	glRasterPos2f(x, y);
	
	for (; aux < n; aux++) {
        glutBitmapCharacter(font, string[aux]);
    }
}

void Venceu()
{
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	RenderString(110.0f, 150.0f, GLUT_BITMAP_HELVETICA_18, "Voce venceu!");
	RenderString(90.0f, 130.0f, GLUT_BITMAP_HELVETICA_10, "Pressione qualquer tecla para reiniciar");
	posicaoXObjeto = 0;
	posicaoYObjeto = 0;
	vidas = 4;
	glFlush();
}

void VerificaColisao() {
	if(VerificaPosicao((posicaoXObjeto+87.5), (posicaoYObjeto+60.82)) == 0) PerdeVida();
	if(VerificaPosicao((posicaoXObjeto+81.25), (posicaoYObjeto+51)) == 0) PerdeVida();
	if(VerificaPosicao((posicaoXObjeto+93.75), (posicaoYObjeto+51)) == 0) PerdeVida();
	if(VerificaPosicao((posicaoXObjeto+87.5), (posicaoYObjeto+60.82)) == 2) Venceu();
	if(VerificaPosicao((posicaoXObjeto+81.25), (posicaoYObjeto+51)) == 2) Venceu();
	if(VerificaPosicao((posicaoXObjeto+93.75), (posicaoYObjeto+51)) == 2) Venceu();
}

int VerificaPosicao(float x, float y)
{
	if(50.0 > y ||  y > 275.0)
	{
		return 0;
	} 
	if(50.0 < y &&  y < 100.0)
	{
		if(100 > x && x >75) return 1;
		return 0;
	} 
	if(100.0 < y &&  y < 125.0)
	{
		if((100 > x && x >75) || (150<x && x<250))return 1;
		return 0;
	} 
	
	if(125.0 < y && y < 150.0)
	{
		if((100 > x && x >25) || (150<x && x<175) || (225<x && x<250))return 1;
		return 0;
	}
	if(150.0 < y &&  y < 200.0)
	{
		if((50 > x && x >25) || (150<x && x<175) || (225<x && x<250))return 1;
		return 0;
	}
	if(200.0 < y && y < 225.0)
	{
		if((175 > x && x >25) || (225<x && x<250))return 1;
		return 0;
	}
	if(225.0 < y && y < 250.0)
	{
		if(250 > x && x >225)return 1;
		return 0;
		
	}
	if(250.0 < y && y < 275.0)
	{
		if(225 < x && x < 300) return 1;
		else if(x >= 300) return 2;
		return 0;
	}
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

void MudaCores(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
         if (state == GLUT_DOWN) {
         	a = rand() % 15;
			b = rand() % 15;
			c = rand() % 15;
         }
    glutPostRedisplay();
}

void Desenha(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
                   
    // Limpa a janela de visualização com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT);
    DesenhaLabirinto();
  	DesenhaObjeto();
  	VerificaColisao();
  	
    // Executa os comandos OpenGL
    glFlush();
}

// Inicializa parâmetros de rendering
void Inicializa (void)
{   
    // Define a cor de fundo da janela de visualização como branca
    glClearColor(cores[c], cores[c], cores[c], 1.0f);
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
	 glutMouseFunc(MudaCores);
     Inicializa();
     glutMainLoop();
}
