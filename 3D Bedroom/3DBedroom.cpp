#include<windows.h>
#include <iostream>
#include<GL/gl.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <bits/stdc++.h>
#include<GL/gl.h>
#include<windows.h>
#include<math.h>
double windowHeight=800, windowWidth=600;
double eyeX=7.0, eyeY=2.0, eyeZ=15.0, refX = 0, refY=0,refZ=0;
double theta = 180.0, y = 1.36, z = 7.97888, a=2;
static GLfloat v_cube[8][3] =
{
{0.0, 0.0, 0.0}, //0
{0.0, 0.0, 3.0}, //1
{3.0, 0.0, 3.0}, //2
{3.0, 0.0, 0.0}, //3
{0.0, 3.0, 0.0}, //4
{0.0, 3.0, 3.0}, //5
{3.0, 3.0, 3.0}, //6
{3.0, 3.0, 0.0} //7
};
static GLubyte quadIndices[6][4] =
{
{0, 1, 2, 3}, //bottom
{4, 5, 6, 7}, //top
{5, 1, 2, 6}, //front
{0, 4, 7, 3}, // back is clockwise
{2, 3, 7, 6}, //right
{1, 5, 4, 0} //left is clockwise
};

static GLfloat colors[6][3] =
{

{0.4, 0.1, 0.0}, //bottom
{0.6, 0.0, 0.7}, //top
{0.0, 1.0, 0.0},
{0.0, 1.0, 1.0},
{0.8, 0.0, 0.0},
{0.3, 0.6, 0.7}
};

void drawCube()
{
glBegin(GL_QUADS);
for (GLint i = 0; i <6; i++)
{
glVertex3fv(&v_cube[quadIndices[i][0]][0]);
glVertex3fv(&v_cube[quadIndices[i][1]][0]);
glVertex3fv(&v_cube[quadIndices[i][2]][0]);
glVertex3fv(&v_cube[quadIndices[i][3]][0]);
}
glEnd();
}
void base(){
//right wall
glColor3f(1, 0.8, 0.5);
glPushMatrix();
glTranslatef(-1.5,-1,.5);
glScalef(5, 2, 0.1);
drawCube();
glPopMatrix();


// left wall
glColor3f(1, 0.8, 0.7);
glPushMatrix();
glTranslatef(-4.5,-1,0);
glScalef(1, 2, 5);
drawCube();
glPopMatrix();


//ceiling
glColor3f(1.0, 0.9, 0.8);
glPushMatrix();
glTranslatef(-2,5.1,0);
glScalef(5, 0.1, 7);
drawCube();
glPopMatrix();

// floor
glColor3f(0.545,0.537,0.537);
glPushMatrix();
glScalef(5, 0.1, 7);
glTranslatef(-1,-5,0);
drawCube();
glPopMatrix();

}

void bed()
{
//bed headboard
glColor3f(0.5,0.2,0.2);
glPushMatrix();
glScalef(0.1, 0.5, 0.9);
glTranslatef(-2,-0.5,6);
drawCube();
glPopMatrix();
//bed body
glColor3f(0.411,0.545,0.411);
glPushMatrix();
glScalef(1, 0.2, 0.9);
glTranslatef(0,-0.5,6.2);
drawCube();
glPopMatrix();
//pillow right far
glColor3f(0.627, 0.322, 0.176);
glPushMatrix();
glTranslatef(0.5,0.5,6);
glRotatef(20, 0,0,1);
glScalef(0.1, 0.15, 0.28);
drawCube();
glPopMatrix();
//pillow left near
glColor3f(0.627, 0.322, 0.176);

glPushMatrix();
glTranslatef(0.5,0.5,7.2);
glRotatef(22, 0,0,1);
glScalef(0.1, 0.15, 0.28);
drawCube();
glPopMatrix();
//blanket
glColor3f(0.627, 0.322, 0.176);
glPushMatrix();
glTranslatef(1.4,0.45,5.5);
glScalef(0.5, 0.05, 0.95);
drawCube();
glPopMatrix();
//blanket side left part
glColor3f(0.627, 0.322, 0.176);
glPushMatrix();
glTranslatef(1.4,-0.3,8.15);
glScalef(0.5, 0.25, 0.05);
drawCube();
glPopMatrix();
}
void cupboard()
{
//cupboard
glColor3f(0.5,0.2,0.2); //0.3,0.1,0.0
glPushMatrix();
glTranslatef(4,0,4.4);
glScalef(0.5, 1, 0.5);
drawCube();
glPopMatrix();
//cupboard's 1st vertical stripline
glColor3f(0.2,0.1,0.1);
glPushMatrix();
glTranslatef(4,1,5.9);
glScalef(0.5, 0.01, 0.0001);
drawCube();

glPopMatrix();
//cupboard's 2nd vertical stripline
glColor3f(0.2,0.1,0.1);
glPushMatrix();
glTranslatef(4,0.5,5.9);
glScalef(0.5, 0.01, 0.0001);
drawCube();
glPopMatrix();
//cupboard's last stripline
glColor3f(0.2,0.1,0.1);
glPushMatrix();
glTranslatef(4,0,5.9);
glScalef(0.5, 0.01, 0.0001);
drawCube();
glPopMatrix();
//cupboard's lst horizontal stripline
glColor3f(0.2,0.1,0.1);
glPushMatrix();
glTranslatef(5.5,0,5.9);
glScalef(0.01, 1, 0.0001);
drawCube();
glPopMatrix();
//cupboard's right side horizontal stripline
glColor3f(0.2,0.1,0.1);
glPushMatrix();
glTranslatef(4.75,1,5.9);
glScalef(0.01, 0.67, 0.0001);
drawCube();
glPopMatrix();
//cupboard's left side horizontal stripline
glColor3f(0.2,0.1,0.1);
glPushMatrix();
glTranslatef(4,0,5.9);
glScalef(0.01, 1, 0.0001);
drawCube();
glPopMatrix();
//cupboard's handle right
glColor3f(0.2,0.1,0.1);

glPushMatrix();
glTranslatef(5,1.4,5.9);
glScalef(0.02, 0.18, 0.0001);
drawCube();
glPopMatrix();
//cupboard's handle left
glColor3f(0.2,0.1,0.1);
glPushMatrix();
glTranslatef(4.5,1.4,5.9);
glScalef(0.02, 0.18, 0.01);
drawCube();
glPopMatrix();
//cupboard's drawer's 1st handle
glColor3f(0.2,0.1,0.1);
glPushMatrix();
glTranslatef(4.5,0.7,5.9);
glScalef(0.16, 0.02, 0.01);
drawCube();
glPopMatrix();
//cupboard's drawer's 2nd handle
glColor3f(0.2,0.1,0.1);
glPushMatrix();
glTranslatef(4.5,0.25,5.9);
glScalef(0.16, 0.02, 0.01);
drawCube();
glPopMatrix();
}

void bedsideTable()
{
//side drawer
glColor3f(0.2,0.1,0.1);
glPushMatrix();
glTranslatef(0.5,-0.1,8.7);
glScalef(0.12, 0.2, 0.23);
drawCube();
glPopMatrix();
//side drawer's drawer
glColor3f(0.3,0.2,0.2);

glPushMatrix();
glTranslatef(0.88,0,8.8);
glScalef(0.0001, 0.11, 0.18);
drawCube();
glPopMatrix();
//side drawer's knob
glColor3f(0.3, 0.1, 0.0);
glPushMatrix();
glTranslatef(0.9,0.1,9);
glScalef(0.0001, 0.04, 0.04);
drawCube();
glPopMatrix();
}




void wallshelf()
{
//wall shelf one
glColor3f(0.2,0.1,0.1);
glPushMatrix();
glTranslatef(1.5,2.7,3);
glScalef(0.4, 0.03, 0.2);
drawCube();
glPopMatrix();
//wall shelf two
glColor3f(0.2,0.1,0.1);
glPushMatrix();
glTranslatef(1,2.3,3);
glScalef(0.4, 0.03, 0.2);
drawCube();
glPopMatrix();
//wall shelf three
glColor3f(0.2,0.1,0.1);
glPushMatrix();
glTranslatef(0.5,1.9,3);
glScalef(0.4, 0.03, 0.2);
drawCube();
glPopMatrix();
//wall shelf four
glColor3f(0.2,0.1,0.1);
glPushMatrix();
glTranslatef(1,1.5,3);
glScalef(0.4, 0.03, 0.2);
drawCube();

glPopMatrix();
//wall shelf five
glColor3f(0.2,0.1,0.1);
glPushMatrix();
glTranslatef(1.5,1.1,3);
glScalef(0.4, 0.03, 0.2);
drawCube();
glPopMatrix();
//showpiece on the bottom shelf from left 1
glColor3f(0.698, 0.133, 0.133);
glPushMatrix();
glTranslatef(1.5,1.2,3);
glScalef(0.04, 0.06, 0.2);
drawCube();
glPopMatrix();
//showpiece on the bottom shelf from left 2
glColor3f(0.729, 0.333, 0.827);
glPushMatrix();
glTranslatef(2,1.2,3);
glScalef(0.04, 0.06, 0.2);
drawCube();
glPopMatrix();
//showpiece on the bottom shelf from left 3 lower portion
glColor3f(0.098, 0.098, 0.439);
glPushMatrix();
glTranslatef(2.5,1.2,3);
glScalef(0.04, 0.06, 0.2);
drawCube();
glPopMatrix();
//showpiece on the bottom shelf from left 3 upper portion
glColor3f(.529, 0.808, 0.980);
glPushMatrix();
glTranslatef(2.51,1.35,3);
glScalef(0.01, 0.05, 0.2);
drawCube();
glPopMatrix();
//showpiece on the top shelf left 2
glColor3f(0.502, 0.502, 0.000);

glPushMatrix();
glTranslatef(2.5,2.71,3);
glScalef(0.05, 0.16, 0.01);
drawCube();
glPopMatrix();
//showpiece on the top shelf left 1
glColor3f(0,0,.9);
glPushMatrix();
glTranslatef(1.8,2.71,3);
glScalef(0.16, 0.1, 0.01);
drawCube();
glPopMatrix();
//showpiece on 2nd shelf
glColor3f(.416, 0.353, 0.804);
glPushMatrix();
glTranslatef(1.3,2.4,3);
glScalef(0.16, 0.08, 0.01);
drawCube();
glPopMatrix();
//showpiece on 3rd shelf left 1
glColor3f(0.863, 0.078, 0.235);
glPushMatrix();
glTranslatef(0.4,1.9,3);
glScalef(0.05, 0.16, 0.01);
drawCube();
glPopMatrix();
//showpiece on 3rd shelf left 2
glColor3f(0.780, 0.082, 0.522);
glPushMatrix();
glTranslatef(0.7,1.9,3);
glScalef(0.05, 0.12, 0.01);
drawCube();
glPopMatrix();
//showpiece on 3rd shelf left 3
glColor3f(0.600, 0.196, 0.800);
glPushMatrix();
glTranslatef(1,1.9,3);
glScalef(0.05, 0.09, 0.01);
drawCube();

glPopMatrix();
//showpiece on 4th shelf
glColor3f(0.282, 0.239, 0.545);
glPushMatrix();
glTranslatef(1.8,1.5,3);
glScalef(0.2, 0.1, 0.2);
glPopMatrix();
//showpiece on 4th shelf
glColor3f(0.251, 0.878, 0.816);
glPushMatrix();
glTranslatef(1.4,1.5,3);
glScalef(0.15, 0.1, 0.2);
glPopMatrix();
}

void LinkinParkPoster()
{
//poster black
glColor3f(0.0,0.0,0.0);
glPushMatrix();
glTranslatef(-1,1.4,4.6);
glScalef(0.0001, .65, .8);
drawCube();
glPopMatrix();
//Linkin Park logo
glColor3f(1.0,1.0,1.0);
glPushMatrix();
glTranslatef(-0.9,2.1,5.5);
glScalef(0.0001, .02, .25);
drawCube();
glPopMatrix();

//Linkin Park logo
glColor3f(1.0,1.0,1.0);
glPushMatrix();
glTranslatef(-0.9,2.1,6.2);
glRotatef(-14, 1,0,0);
glScalef(0.0001, .28, .02);
drawCube();
glPopMatrix();
//Linkin Park logo
glColor3f(1.0,1.0,1.0);
glPushMatrix();
glTranslatef(-0.9,1.8,6);
glRotatef(-14, 1,0,0);
glScalef(0.0001, .29, .02);
drawCube();
glPopMatrix();
//Linkin Park logo
glColor3f(1.0,1.0,1.0);
glPushMatrix();
glTranslatef(-0.9,2.1,5.5);
glRotatef(23, 1,0,0);
glScalef(0.0001, .25, .02);
drawCube();
glPopMatrix();
}


void wardrobe()
{
//wardrobe
glColor3f(0.3,0.1,0);
glPushMatrix();
glTranslatef(0,0,4);
glScalef(0.12, 0.6, 0.4);
drawCube();
glPopMatrix();
//wardrobe's 1st drawer
glColor3f(0.5,0.2,0.2);
glPushMatrix();
glTranslatef(0.36,1.4,4.05);

glScalef(0.0001, 0.11, 0.38);
drawCube();
glPopMatrix();
//wardrobe's 2nd drawer
glColor3f(0.5,0.2,0.2);
glPushMatrix();
glTranslatef(0.36,1,4.05);
glScalef(0.0001, 0.11, 0.38);
drawCube();
glPopMatrix();
//wardrobe's 3rd drawer
glColor3f(0.5,0.2,0.2);
glPushMatrix();
glTranslatef(0.36,0.6,4.05);
glScalef(0.0001, 0.11, 0.38);
drawCube();
glPopMatrix();
//wardrobe's 4th drawer
glColor3f(0.5,0.2,0.2);
glPushMatrix();
glTranslatef(0.36,0.2,4.05);
glScalef(0.0001, 0.11, 0.38);
drawCube();
glPopMatrix();
//wardrobe's 1st drawer handle
glColor3f(0.3,0.1,0);
glPushMatrix();
glTranslatef(0.37,1.5,4.3);
glScalef(0.0001, 0.03, 0.2);
drawCube();
glPopMatrix();
//wardrobe's 2nd drawer handle
glColor3f(0.3,0.1,0);
glPushMatrix();
glTranslatef(0.37,1.1,4.3);
glScalef(0.0001, 0.03, 0.2);
drawCube();
glPopMatrix();

//wardrobe's 3rd drawer handle
glColor3f(0.3,0.1,0);
glPushMatrix();
glTranslatef(0.37,0.7,4.3);
glScalef(0.0001, 0.03, 0.2);
drawCube();
glPopMatrix();
//wardrobe's 4th drawer handle
glColor3f(0.3,0.1,0);
glPushMatrix();
glTranslatef(0.37,0.3,4.3);
glScalef(0.0001, 0.03, 0.2);
drawCube();
glPopMatrix();
//wardrobe left stripline
glColor3f(0.5,0.2,0.2);
glPushMatrix();
glTranslatef(0.35,0,5.3);
glScalef(0.01, 0.6, 0.0001);
drawCube();
glPopMatrix();
}

void window()
{
//window white open
glColor3f(1.0,1.0,1.0);
glPushMatrix();
glTranslatef(-0.9,1,8.9);
glScalef(0.0001, .6, .3);
drawCube();
glPopMatrix();
//window side corner
glColor3f(0.8,0.6,0.4);
glPushMatrix();
glTranslatef(-0.9,1,8.9);
glScalef(0.04, 0.6, 0.0001);
drawCube();
glPopMatrix();

//window left side corner
glColor3f(0.8,0.6,0.4);
glPushMatrix();
glTranslatef(-0.9,1,9.8);
glScalef(0.04, 0.6, 0.0001);
drawCube();
glPopMatrix();
//window upper side corner
glColor3f(0.7,0.6,0.5);
glPushMatrix();
glTranslatef(-0.7,2.7,8.9);
glScalef(0.0001, 0.05, 0.4);
drawCube();
glPopMatrix();

//window lower side corner
glColor3f(0.7,0.6,0.5);
glPushMatrix();
glTranslatef(-0.8,1.02,8.9);
glScalef(0.0001, 0.02, 0.34);
drawCube();
glPopMatrix();
//window vertical bar 1
glColor3f(0.0,0.0,0.0);
glPushMatrix();
glTranslatef(-0.87,2.1,8.9);
glScalef(0.0001, 0.02, 0.3);
drawCube();
glPopMatrix();
//window vertical bar 2
glColor3f(0.0,0.0,0.0);
glPushMatrix();
glTranslatef(-0.87,1.6,8.9);
glScalef(0.0001, 0.02, 0.3);
drawCube();
glPopMatrix();
//window horizontal bar
glColor3f(0.0,0.0,0.0);
glPushMatrix();

glTranslatef(-0.87,1,9.3);
glScalef(0.0001, 0.6, 0.02);
drawCube();
glPopMatrix();
}

void dressingtable()
{
//dressing table left body
glColor3f(0.545, 0.271, 0.075);
glPushMatrix();
glTranslatef(6.15,0,4.6);
glScalef(0.05, 0.2, 0.2);
drawCube();
glPopMatrix();
//dressing table left body left stripe
glColor3f(0.2,0.1,0.1);
glPushMatrix();
glTranslatef(6.12,0,5.2);
glScalef(0.01, 0.3, 0.0001);
drawCube();
glPopMatrix();
//dressing table left body right stripe
glColor3f(0.2,0.1,0.1);
glPushMatrix();
glTranslatef(6.15,0,5.2);
glScalef(0.01, 0.2, 0.0001);
drawCube();
glPopMatrix();

//dressing table right body
glColor3f(0.545, 0.271, 0.075);

glPushMatrix();
glTranslatef(6.75,0,4.6);
glScalef(0.2, 0.2, 0.2);
drawCube();
glPopMatrix();
//dressing table right body left stripe
glColor3f(0.2,0.1,0.1);
glPushMatrix();
glTranslatef(6.75,0,5.2);
glScalef(0.01, 0.2, 0.0001);
drawCube();
glPopMatrix();
//dressing table right body right stripe
glColor3f(0.2,0.1,0.1);
glPushMatrix();
glTranslatef(7.34,0,5.2);
glScalef(0.01, 0.3, 0.0001);
drawCube();
glPopMatrix();
//dressing table right body bottom stripe
glColor3f(0.2,0.1,0.1);
glPushMatrix();
glTranslatef(6.75,0,5.2);
glScalef(0.2, 0.01, 0.0001);
drawCube();
glPopMatrix();
//dressing table upper body
glColor3f(0.545, 0.271, 0.075);
glPushMatrix();
glTranslatef(6.14,0.6,4.6);
glScalef(0.4, 0.1, 0.2);
drawCube();
glPopMatrix();
//dressing table upper body bottom stripe
glColor3f(0.2,0.1,0.1);
glPushMatrix();
glTranslatef(6.12,0.6,5.2);
glScalef(0.4, 0.01, 0.0001);
drawCube();

glPopMatrix();
//dressing table upper body upper stripe
glColor3f(0.2,0.1,0.1);
glPushMatrix();
glTranslatef(6.12,0.9,5.2);
glScalef(0.4, 0.01, 0.0001);
drawCube();
glPopMatrix();
//dressing table upper body handle
glColor3f(0.2,0.1,0.1);
glPushMatrix();
glTranslatef(6.5,0.75,5.2);
glScalef(0.16, 0.02, 0.0001);
drawCube();
glPopMatrix();

//dressing table right body handle
glColor3f(0.2,0.1,0.1);
glPushMatrix();
glTranslatef(6.9,0.1,5.2);
glScalef(0.02, 0.13, 0.0001);
drawCube();
glPopMatrix();
//dressing table main mirror
glColor3f(0.690, 0.878, 0.902);
glPushMatrix();
glTranslatef(6.2,0.9,4.7);
glScalef(0.36, 0.5, 0.0001);
drawCube();
glPopMatrix();


//dressing table  left stripe
glColor3f(0.2,0.1,0.1);
glPushMatrix();
glTranslatef(6.17,0.98,4.71);
glScalef(0.019, 0.48, 0.0001);
drawCube();
glPopMatrix();
//dressing table mirror bottom stripe
glColor3f(0.2,0.1,0.1);
glPushMatrix();
glTranslatef(6.16,0.9,4.71);
glScalef(0.39, 0.019, 0.0001);
drawCube();
glPopMatrix();



glPopMatrix();

//dressing table right stripe
glColor3f(0.2,0.1,0.1);
glPushMatrix();
glTranslatef(7.25,0.98,4.71);
glScalef(0.019, 0.48, 0.0001);
drawCube();
glPopMatrix();


//dressing  upper stripe
glColor3f(0.2,0.1,0.1);
glPushMatrix();
glTranslatef(6.2,2.4,4.71);
glScalef(0.35, 0.019, 0.0001);
drawCube();
glPopMatrix();


}
void AC()
{
 glColor3f(1.0,1.0,1.0);
glPushMatrix();
glTranslatef(-2,4.0,0.5);
glScalef(0.2,0.2,1);
drawCube();
glPopMatrix();






}






void display(void)
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glMatrixMode( GL_PROJECTION );
glLoadIdentity();
gluPerspective(60,1,1,100);
glMatrixMode( GL_MODELVIEW );
glLoadIdentity();
gluLookAt(eyeX,eyeY,eyeZ, refX,refY,refZ, 0,1,0); //7,2,15, 0,0,0, 0,1,0

glViewport(0, 0, 800, 600);

base();
window();
bed();
bedsideTable();
cupboard();
wallshelf();
LinkinParkPoster();
wardrobe();
dressingtable();
AC();


glFlush();
glutSwapBuffers();
}
void myKeyboardFunc( unsigned char key, int x, int y )
{
switch ( key )
{
case 'w': // move eye point upwards along Y axis
eyeY+=1.0;
break;
case 's': // move eye point downwards along Y axis
eyeY-=1.0;
break;
case 'a': // move eye point left along X axis
eyeX-=1.0;
break;
case 'd': // move eye point right along X axis
eyeX+=1.0;
break;
case 'o': //zoom out
eyeZ+=1;
break;
case 'i': //zoom in
eyeZ-=1;
break;
case 'q': //back to default eye point and ref point
eyeX=7.0; eyeY=2.0; eyeZ=15.0;
refX=0.0; refY=0.0; refZ=0.0;
break;

case 'j': // move ref point upwards along Y axis
refY+=1.0;
break;
case 'n': // move ref point downwards along Y axis
refY-=1.0;
break;
case 'b': // move ref point left along X axis
refX-=1.0;
break;
case 'm': // move eye point right along X axis
refX+=1.0;
break;
case 'k': //move ref point away from screen/ along z axis
refZ+=1;
break;
case 'l': //move ref point towards screen/ along z axis
refZ-=1;
break;
case 27: // Escape key
exit(1);
}
glutPostRedisplay();
}

int main (int argc, char **argv)
{
glutInit(&argc, argv);
std::cout<<"To move Eye point:"<< std::endl;
std::cout<<"w: up"<<std::endl;
std::cout<<"s: down"<<std::endl;
std::cout<<"a: left"<<std::endl;
std::cout<<"d: right"<<std::endl;
std::cout<<"i: zoom in"<<std::endl;
std::cout<<"o: zoom out"<<std::endl;
std::cout<<" "<<std::endl;
std::cout<<"To move Camera point:"<< std::endl;
std::cout<<"j: up"<<std::endl;
std::cout<<"n: down"<<std::endl;
std::cout<<"b: left"<<std::endl;

std::cout<<"m: right"<<std::endl;
std::cout<<"l: move nearer"<<std::endl;
std::cout<<"k: move far"<<std::endl;
std::cout<<" "<<std::endl;
std::cout<<"Press q to move to default position"<<std::endl;
std::cout<<" "<<std::endl;
std::cout<<" "<<std::endl;
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
glutInitWindowPosition(100,100);
glutInitWindowSize(windowHeight, windowWidth);
glutCreateWindow("1607063 Bedroom");
glShadeModel( GL_SMOOTH );
glEnable( GL_DEPTH_TEST );
glutDisplayFunc(display);
glutKeyboardFunc(myKeyboardFunc);
glutMainLoop();
return 0;
}
