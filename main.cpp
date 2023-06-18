
#include <GL/glut.h>
#include <windows.h>
#include <math.h>
#include <unistd.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

//--------------------------------------------------Global Declarations -----------------------------------------------------

// define variables to hold our window IDs
int window1, window2,window3,window4;

// Button coordinates
int button_x = -50, button_y = -240;
int button_w = 70, button_h = 50;

float cameraX = 10.0;
float cameraY = 10.0;
float cameraZ = 10.0;
float cameraAngleX = 5.0;
float cameraAngleY = 5.0;

// Light state variable
bool light_on;


//-----------------------------------------------All the functions declaration---------------------------------------------
void init();

void displaynames();

void display1();

void display2();

void line(int x);

void grass(int x);

void drawStickman();

void drawStickman2();

void drawStickman3();

void drawStickmanZombie();

void display2to3();

void display3();

void display4();

void displaybedroom();

void displaykitchen();

void displaycropr();

void displaywater();

void mouse3(int button, int state, int x, int y);

void mouse2(int button, int state, int x, int y);

void mouse1(int button, int state, int x, int y);

void mouse(int button, int state, int x, int y);

void mykey(unsigned char key,int x,int y);

void mykey1(unsigned char key,int x,int y);

void mapunder();

void reshape(int width, int height);

void bgmaincolour();

void drawTableLeg(float x, float y, float z, float width, float height);

void gameover();

void exitkey(unsigned char key,int x,int y);

void destruct(unsigned char key,int x,int y);

//--------------------------------------------Main Function---------------------------------------

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // initialize the GLUT library
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set the display mode
    glutInitWindowSize(1590, 760); // set the window size

    glutInitWindowPosition(0, 0); // set the window position
    window1 = glutCreateWindow("Main Page"); // create the first window with the specified title
    glutFullScreen();
    init(); // initialize OpenGL
    glutDisplayFunc(display1); // set the display function for the first window
    glutMouseFunc(mouse);
    glutKeyboardFunc(mykey1);
    glutMainLoop(); // enter the main loop and start processing events
    return 0;
}

//-------------------------------------------Function definition--------------------------------

void gameover()
{
    glClear(GL_COLOR_BUFFER_BIT); // clear the window
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( -300, 300, -300, 300, -1, 1 );
    glColor3f(1.0f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(1, 0.0, 0.0);
    glVertex2f(-500, 300.0);
    glVertex2f(500.0, 300.0);
    glColor3f(1,0,0);
    glVertex2f(500.0, 150.0);
    glVertex2f(-500, 150.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex2f(-500, 150.0);
    glVertex2f(500.0, 150.0);
    glColor3f(1,0,0);
    glVertex2f(500.0, 50);
    glVertex2f(-500, 50);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1,0, 0.0);
    glVertex2f(-500, 50);
    glVertex2f(500.0, 50);
    glColor3f(1, 0, 0);
    glVertex2f(500.0, -600);
    glVertex2f(-500, -600);
    glEnd();

      glColor3f(0.0,0.0,0.0);
    glRasterPos2i(-45,-10);
// Draw text
    char text[] = "Game Over !! ";
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }

      glFlush(); // Flush the buffer

}

void drawTableLeg(float x, float y, float z, float width, float height)
{
    glPushMatrix();
    glTranslatef(x, y, z); // Translate to the starting position of the leg
    glScalef(width, height, width); // Scale the leg to desired width and height
    glutSolidCube(1.0); // Draw a solid cube as the leg
    glPopMatrix();
}

void bgmaincolour()
{
    // draw green section
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(-500, 300.0);
    glVertex2f(500.0, 300.0);
    glColor3f(0.6, 0.3, 0.0);
    glVertex2f(500.0, 150.0);
    glVertex2f(-500, 150.0);
    glEnd();

    // draw brown section
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.3, 0.0);
    glVertex2f(-500, 150.0);
    glVertex2f(500.0, 150.0);
    glColor3f(0.5, 0.25, 0.0);
    glVertex2f(500.0, 50);
    glVertex2f(-500, 50);
    glEnd();

    // draw grey section
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.25, 0.0);
    glVertex2f(-500, 50);
    glVertex2f(500.0, 50);
    glColor3f(0.5, 0.5, 0.5);
    glVertex2f(500.0, -600);
    glVertex2f(-500, -600);
    glEnd();

}

void mapunder()
{
    //Sky with Blue color
    glColor3f(0.60784313725, 0.82745, 0.86666);
    glBegin(GL_QUADS);
    glVertex2i(-360,200);
    glVertex2i(-360,320);
    glVertex2i(400,320);
    glVertex2i(400,200);
    glEnd();

    //Grass with green color
    glColor3f(0.0, 0.6039, 0.09019);

    glBegin(GL_LINES);
    glVertex2f(-340.0,200.0 );
    glVertex2f(340.0, 200.0);
    glEnd();

    for(int i=-200; i<=200; i=i+50)
    {
        grass(i);
    }

    glBegin(GL_LINES);
    glVertex2f(-340.0,199.0 );
    glVertex2f(340.0, 199.0);
    glEnd();
    glColor3f(0.8f,0.4f,0.1f);
    glBegin(GL_LINES);
    glVertex2f(-340.0,198.0 );
    glVertex2f(340.0, 198.0);
    glEnd();

    glColor3f(0.7f,0.4f,0.1f);
    glBegin(GL_QUADS);
    glVertex2f(-70,198.0 );
    glVertex2f(-60,198.0 );
    glVertex2f(-60, 170.0);
    glVertex2f(-70, 170.0);

    //MAIN ROOM
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
    glVertex2i(-90,170);
    glVertex2i(10,170);
    glVertex2i(10,70);
    glVertex2i(-90,70);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2i(-63, 125);
    char* t = "MAIN ROOM";
    int length=strlen(t);
    for (int i = 0; i < length; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, t[i]);
    }



    glColor3f(0.7,0.4,0.1);
    glBegin(GL_QUADS);
    glVertex2i(-90,100);
    glVertex2i(-110,40);
    glVertex2i(-110,10);
    glVertex2i(-90,70);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(-70,-70);
    glVertex2i(-70,-40);
    glVertex2i(-110,40);
    glVertex2i(-110,10);

    glColor3f(0.6,0.4,0.1);
    glBegin(GL_QUADS);
    glVertex2i(-115,40);
    glVertex2i(-115,10);
    glVertex2i(-100,10);
    glVertex2i(-100,40);

    //KITCHEN
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
    glVertex2i(-70,30);
    glVertex2i(30,30);
    glVertex2i(30,-70);
    glVertex2i(-70,-70);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glRasterPos2i(-51, -20);
    t = "KITCHEN & DINING";
    length=strlen(t);
    for (int i = 0; i < length; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, t[i]);
    }

    glColor3f(0.7,0.4,0.1);
    glBegin(GL_QUADS);
    glVertex2i(-70,-40);
    glVertex2i(-70,-70);
    glVertex2i(-110,-160);
    glVertex2i(-110,-130);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(-20,-210);
    glVertex2i(-20,-240);
    glVertex2i(-110,-160);
    glVertex2i(-110,-130);
    glEnd();

    glColor3f(0.6,0.4,0.1);
    glBegin(GL_QUADS);
    glVertex2i(-115,-160);
    glVertex2i(-115,-130);
    glVertex2i(-100,-130);
    glVertex2i(-100,-160);
    glEnd();

    //ER
    glColor3f(0.5, 0.5, 0.5); // White color
    glBegin(GL_QUADS);
    glVertex2i(-20,-150);
    glVertex2i(150,-150);
    glVertex2i(150,-240);
    glVertex2i(-20,-240);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glRasterPos2i(30, -200);
    t = "EMERGENCY ROOM";
    length=strlen(t);
    for (int i = 0; i < length; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, t[i]);
    }

    glColor3f(0.7, 0.4, 0.1);
    glBegin(GL_QUADS);
    glVertex2i(150,-180);
    glVertex2i(150,-200);
    glVertex2i(200,-200);
    glVertex2i(200,-180);
    glEnd();


    glColor3f(0.7, 0.4, 0.1);
    glBegin(GL_QUADS);
    glVertex2i(200,-180);
    glVertex2i(200,228);
    glVertex2i(190,228);
    glVertex2i(190,-180);
    glEnd();

    glColor3f(0.7, 0.5, 0.1);
    glBegin(GL_QUADS);
    glVertex2i(205,250);
    glVertex2i(205,228);
    glVertex2i(185,228);
    glVertex2i(185,250);
    glEnd();

    //BEDROOM
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
    glVertex2i(50,170);
    glVertex2i(140,170);
    glVertex2i(140,70);
    glVertex2i(50,70);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glRasterPos2i(80, 120);
    t = "BEDROOM";
    length=strlen(t);
    for (int i = 0; i < length; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, t[i]);
    }


    glColor3f(0.7, 0.4, 0.1);
    glBegin(GL_QUADS);
    glVertex2i(10,140);
    glVertex2i(10,125);
    glVertex2i(50,125);
    glVertex2i(50,140);
    glEnd();

    //Air and Water
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
    glVertex2i(-205,90);
    glVertex2i(-115,90);
    glVertex2i(-115,10);
    glVertex2i(-205,10);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glRasterPos2i(-180, 40);
    t = "WATER & AIR";
    length=strlen(t);
    for (int i = 0; i < length; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, t[i]);
    }

    //FOOD CROPS
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
    glVertex2i(-210,-60);
    glVertex2i(-115,-60);
    glVertex2i(-115,-160);
    glVertex2i(-210,-160);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glRasterPos2i(-180, -130);
    t = "FOOD CROPS";
    length=strlen(t);
    for (int i = 0; i < length; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, t[i]);
    }

    //Borders
    glColor3f(0.0f,0.0f,0.0f);
    glLineWidth(2);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_POLYGON);
    glVertex2i(-90,170);
    glVertex2i(-90,70);
    glVertex2i(10,70);
    glVertex2i(10,170);
    glEnd();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_POLYGON);
    glVertex2i(50,170);
    glVertex2i(50,70);
    glVertex2i(140,70);
    glVertex2i(140,170);
    glEnd();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_POLYGON);
    glVertex2i(-205,90);
    glVertex2i(-205,10);
    glVertex2i(-115,10);
    glVertex2i(-115,90);
    glEnd();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);



    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_POLYGON);
    glVertex2i(-20,-150);
    glVertex2i(-20,-240);
    glVertex2i(150,-240);
    glVertex2i(150,-150);
    glEnd();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_POLYGON);
    glVertex2i(-70,30);
    glVertex2i(-70,-70);
    glVertex2i(30,-70);
    glVertex2i(30,30);
    glEnd();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_POLYGON);
    glVertex2i(-210,-60);
    glVertex2i(-210,-160);
    glVertex2i(-115,-160);
    glVertex2i(-115,-60);
    glEnd();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_POLYGON);
    glVertex2i(-70,30);
    glVertex2i(-70,-70);
    glVertex2i(30,-70);
    glVertex2i(30,30);
    glEnd();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);






}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0); // set the clear color to black
}

void displaynames()
{
// Set text position
    glColor3f(0.0,0.0,0.0);
    glRasterPos2i(-85,220);
// Draw text
    char text[] = "MINI PROJECT ON COMPUTER GRAPHICS ";
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }


    glColor3f(1.0,0.0,0.0);
    glRasterPos2i(-70,190);
    // Draw text
    char ug[] = "UNDERGROUND BUNKER  ";
    length = strlen(ug);
    for (int i = 0; i < length; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ug[i]);
    }

    glColor3f(0.0, 1.0, 0.0); // set the drawing color to white

    glRasterPos2i(20,190);
    // Draw text
    char tex[] = "\[ \_o\-o \] \_";
    length = strlen(tex);
    for (int i = 0; i < length; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, tex[i]);
    }
    // Set text position
    glRasterPos2i(-15,176);

    // Draw text
    char te[] = "                      I          I";
    length = strlen(te);
    for (int i = 0; i < length; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, te[i]);
    }

    glColor3f(0.59215,0.007843,0.59215);
    glRasterPos2i(-100,150);
    char textl[] = "By";
    length = strlen(textl);
    for (int i = 0; i < length; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, textl[i]);
    }

    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2i(-60,130);
    char text2[] = "Ardra";
    length = strlen(text2);
    for (int i = 0; i < length; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text2[i]);
    }

    glRasterPos2i(0,130);
    char text3[] = "4NM20CS039";
    length = strlen(text3);
    for (int i = 0; i < length; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text3[i]);
    }

    glRasterPos2i(-60,90);
    char text4[] = "Avaneesh";
    length = strlen(text4);
    for (int i = 0; i < length; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text4[i]);
    }


    glRasterPos2i(0,90);
    char text5[] = "4NM20CS044";
    length = strlen(text5);
    for (int i = 0; i < length; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text5[i]);
    }

    glColor3f(0.59215,0.007843,0.59215);


    glRasterPos2i(-100,35);
    char text6[] = "Under the Guidance of -";
    length = strlen(text6);
    for (int i = 0; i < length; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text6[i]);
    }

    glColor3f(0.0, 0.0, 0.0); // set the drawing color to white
    glRasterPos2i(-70,0);
    char pk[] = "Dr. Pradeep Kanchan";
    length = strlen(pk);
    for (int i = 0; i < length; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, pk[i]);
    }


    glRasterPos2i(-70,-35);
    char sm[] = "Ms. Shruthi M.";
    length = strlen(sm);
    for (int i = 0; i < length; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, sm[i]);
    }
}

void display1()
{
    glClear(GL_COLOR_BUFFER_BIT); // clear the window
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( -300, 300, -300, 300, -1, 1 );
    glColor3f(1.0f, 0.0f, 0.0f);

    displaynames();  //To display names and USN

    glColor3f(0.5, 0.5, 0.5); // White color
    glBegin(GL_QUADS);
    glVertex2i(button_x, button_y);
    glVertex2i(button_x + button_w, button_y);
    glVertex2i(button_x + button_w, button_y + button_h);
    glVertex2i(button_x, button_y + button_h);
    glEnd();
    // Draw text
    glColor3f(0.0, 0.0, 0.0); // Black color
    glRasterPos2i(button_x + 20, button_y + 25);
    char* t = "Click here";
    int length=strlen(t);
    for (int i = 0; i < length; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, t[i]);
    }
    glFlush(); // draw the rectangle to the screen
}


void grass(int x)
{
    glBegin(GL_LINES);
    glVertex2f(x-5, 210.0);
    glVertex2f(x,200.0 );
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(x,200.0 );
    glVertex2f(x, 210.0);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(x,200.0 );
    glVertex2f(x+5, 210.0);
    glEnd();
}

void display2()
{
    PlaySound(NULL,NULL,0);
    glClear(GL_COLOR_BUFFER_BIT); // clear the window
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( -300, 300, -300, 300, -1, 1 );
    glColor3f(0.0f, 1.0f, 0.0f);


    bgmaincolour();
    mapunder();

    //human stickman
    drawStickman();


    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
    glVertex2i(250,-170);
    glVertex2i(290,-170);
    glVertex2i(290,-210);
    glVertex2i(250,-210);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glRasterPos2i(260, -190);
    char * t = "Return";
    int length=strlen(t);
    for (int i = 0; i < length; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, t[i]);
    }

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_POLYGON);
    glVertex2i(250,-210);
    glVertex2i(250,-170);
    glVertex2i(290,-170);
    glVertex2i(290,-210);
    glEnd();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glFlush(); // draw the rectangle to the screen

}

void drawStickman()
{
    // draw head
    glColor3f(1,1,1); // set color to purple
    glLineWidth(1.0); // set line width
    glBegin(GL_POLYGON); // start drawing a filled polygon
    float radius = 5.0; // head radius
    float x = -66.0; // center x coordinate of head
    float y = 225.0; // center y coordinate of head
    for (int i = 0; i < 360; i += 10) // draw a circle using line segments
    {
        float angle = i * 3.14159 / 180.0;
        glVertex2f(x + radius * cos(angle), y + radius * sin(angle));
    }
    glEnd(); // end drawing

    // draw body
    glBegin(GL_LINES); // start drawing lines
    glVertex2f(x, y - radius); // start from bottom of head
    glVertex2f(x, y - 15.0); // draw line down to bottom of body
    glEnd(); // end drawing

    // draw arms
    glBegin(GL_LINES); // start drawing lines
    glVertex2f(x, y - 10.0); // start from middle of body
    glVertex2f(x - 5.0, y - 5.0); // draw line to left arm
    glVertex2f(x, y - 10.0); // start from middle of body
    glVertex2f(x + 5.0, y - 5.0); // draw line to right arm
    glEnd(); // end drawing

    // draw legs
    glBegin(GL_LINES); // start drawing lines
    glVertex2f(x, y - 15.0); // start from bottom of body
    glVertex2f(x - 5.0, y - 25.0); // draw line to left leg
    glVertex2f(x, y - 15.0); // start from bottom of body
    glVertex2f(x + 5.0, y - 25.0); // draw line to right leg
    glEnd(); // end drawing
}


void drawStickman2()
{
    for(int i=0 ; i<10; i++)
    {
        // draw head
        glColor3f(1,1,1); // set color to purple
        glLineWidth(1.0); // set line width
        glBegin(GL_POLYGON); // start drawing a filled polygon
        float radius = 5.0; // head radius
        float x = -66.0; // center x coordinate of head
        float y = 225.0-i; // center y coordinate of head
        for (int i = 0; i < 360; i += 10) // draw a circle using line segments
        {
            float angle = i * 3.14159 / 180.0;
            glVertex2f(x + radius * cos(angle), y + radius * sin(angle));
        }
        glEnd(); // end drawing

        // draw body
        glBegin(GL_LINES); // start drawing lines
        glVertex2f(x, y - radius); // start from bottom of head
        glVertex2f(x, y - 15.0); // draw line down to bottom of body
        glEnd(); // end drawing

        // draw arms
        glBegin(GL_LINES); // start drawing lines
        glVertex2f(x, y - 10.0); // start from middle of body
        glVertex2f(x - 5.0, y - 5.0); // draw line to left arm
        glVertex2f(x, y - 10.0); // start from middle of body
        glVertex2f(x + 5.0, y - 5.0); // draw line to right arm
        glEnd(); // end drawing

        // draw legs
        glBegin(GL_LINES); // start drawing lines
        glVertex2f(x, y - 15.0); // start from bottom of body
        glVertex2f(x - 5.0, y - 25.0); // draw line to left leg
        glVertex2f(x, y - 15.0); // start from bottom of body
        glVertex2f(x + 5.0, y - 25.0); // draw line to right leg
        glEnd(); // end drawing
        sleep(100000);
    }
}


void drawStickman3()
{
    // draw head
    glColor3f(1,1,1); // set color to purple
    glLineWidth(1.0); // set line width
    glBegin(GL_POLYGON); // start drawing a filled polygon
    float radius = 5.0; // head radius
    float x = -66.0; // center x coordinate of head
    float y = 100.0; // center y coordinate of head
    for (int i = 0; i < 360; i += 10) // draw a circle using line segments
    {
        float angle = i * 3.14159 / 180.0;
        glVertex2f(x + radius * cos(angle), y + radius * sin(angle));
    }
    glEnd(); // end drawing

    // draw body
    glBegin(GL_LINES); // start drawing lines
    glVertex2f(x, y - radius); // start from bottom of head
    glVertex2f(x, y - 15.0); // draw line down to bottom of body
    glEnd(); // end drawing

    // draw arms
    glBegin(GL_LINES); // start drawing lines
    glVertex2f(x, y - 10.0); // start from middle of body
    glVertex2f(x - 5.0, y - 5.0); // draw line to left arm
    glVertex2f(x, y - 10.0); // start from middle of body
    glVertex2f(x + 5.0, y - 5.0); // draw line to right arm
    glEnd(); // end drawing

    // draw legs
    glBegin(GL_LINES); // start drawing lines
    glVertex2f(x, y - 15.0); // start from bottom of body
    glVertex2f(x - 5.0, y - 25.0); // draw line to left leg
    glVertex2f(x, y - 15.0); // start from bottom of body
    glVertex2f(x + 5.0, y - 25.0); // draw line to right leg
    glEnd(); // end drawing
}

void drawStickman4()
{
    // draw head
    glColor3f(1,1,1); // set color to white
    glLineWidth(1.0); // set line width
    glBegin(GL_POLYGON); // start drawing a filled polygon
    float radius = 5.0; // head radius
    float x = -66.0; // center x coordinate of head
    float y = 225.0; // center y coordinate of head
    for (int i = 0; i < 360; i += 10) // draw a circle using line segments
    {
        float angle = i * 3.14159 / 180.0;
        glVertex3f(x + radius * cos(angle), y + radius * sin(angle), 0);
    }
    glEnd(); // end drawing

    // draw body
    glBegin(GL_LINES); // start drawing lines
    glVertex3f(x, y - radius,0); // start from bottom of head
    glVertex3f(x, y - 15.0,0); // draw line down to bottom of body
    glEnd(); // end drawing

    // draw arms
    glBegin(GL_LINES); // start drawing lines
    glVertex3f(x, y - 10.0,0); // start from middle of body
    glVertex3f(x - 5.0, y - 5.0,0); // draw line to left arm
    glVertex3f(x, y - 10.0,0); // start from middle of body
    glVertex3f(x + 5.0, y - 5.0,0); // draw line to right arm
    glEnd(); // end drawing

    // draw legs
    glBegin(GL_LINES); // start drawing lines
    glVertex2f(x, y - 15.0); // start from bottom of body
    glVertex2f(x - 5.0, y - 25.0); // draw line to left leg
    glVertex2f(x, y - 15.0); // start from bottom of body
    glVertex2f(x + 5.0, y - 25.0); // draw line to right leg
    glEnd(); // end drawing

}


void display2to3()
{
    glClear(GL_COLOR_BUFFER_BIT); // clear the window
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( -300, 300, -300, 300, -1, 1 );
    glColor3f(0.0f, 1.0f, 0.0f);


    bgmaincolour();
    mapunder();

    //human stickman

    drawStickman2();


    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
    glVertex2i(250,-170);
    glVertex2i(290,-170);
    glVertex2i(290,-210);
    glVertex2i(250,-210);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glRasterPos2i(260, -190);
    char * t = "Return";
    int length=strlen(t);
    for (int i = 0; i < length; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, t[i]);
    }

    glFlush(); // draw the rectangle to the screen


}

void display3()
{
    PlaySound("zombie.wav",NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    glClear(GL_COLOR_BUFFER_BIT); // clear the window
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( -300, 300, -300, 300, -1, 1 );
    glColor3f(0.0f, 1.0f, 0.0f);

    bgmaincolour();
    mapunder();

    //Cross bars
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-70.0,199.0 );
    glVertex2f(-60.0, 169.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-70.0,169.0 );
    glVertex2f(-60.0, 199.0);
    glEnd();

    //human stickman

    drawStickman3();
    drawStickmanZombie();


    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
    glVertex2i(250,-170);
    glVertex2i(290,-170);
    glVertex2i(290,-210);
    glVertex2i(250,-210);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glRasterPos2i(260, -190);
    char * t = "Return";
    int length=strlen(t);
    for (int i = 0; i < length; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, t[i]);
    }



    glFlush(); // draw the rectangle to the screen
}

void drawStickmanZombie()
{

    for(int ii=0 ; ii<200; ii+=50)
    {
        // draw head
        glColor3f(1,0,0); // set color to purple
        glLineWidth(1.0); // set line width
        glBegin(GL_POLYGON); // start drawing a filled polygon
        float radius = 5.0; // head radius
        float x = -176.0+ii; // center x coordinate of head
        float y = 223.0; // center y coordinate of head
        for (int i = 0; i < 360; i += 10) // draw a circle using line segments
        {
            float angle = i * 3.14159 / 180.0;
            glVertex2f(x + radius * cos(angle), y + radius * sin(angle));
        }
        glEnd(); // end drawing

        // draw body
        glBegin(GL_LINES); // start drawing lines
        glVertex2f(x, y - radius); // start from bottom of head
        glVertex2f(x, y - 15.0); // draw line down to bottom of body
        glEnd(); // end drawing

        // draw arms
        glBegin(GL_LINES); // start drawing lines
        glVertex2f(x, y - 10.0); // start from middle of body
        glVertex2f(x - 5.0, y - 5.0); // draw line to left arm
        glVertex2f(x, y - 10.0); // start from middle of body
        glVertex2f(x + 5.0, y - 5.0); // draw line to right arm
        glEnd(); // end drawing

        // draw legs
        glBegin(GL_LINES); // start drawing lines
        glVertex2f(x, y - 15.0); // start from bottom of body
        glVertex2f(x - 5.0, y - 25.0); // draw line to left leg
        glVertex2f(x, y - 15.0); // start from bottom of body
        glVertex2f(x + 5.0, y - 25.0); // draw line to right leg
        glEnd(); // end drawing
    }


}

void display4()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0, 1.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(65.0,65.0,65.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glRotatef(cameraAngleX, 1.0, 0.0, 0.0);
    glRotatef(cameraAngleY, 0.0, 1.0, 0.0);


    // Draw the floor
    glColor3f(0.6431, 0.4549, 0.2862);
    glBegin(GL_QUADS);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 50.0);
    glVertex3f(50.0, 0.0, 50.0);
    glVertex3f(50.0, 0.0, 0.0);
    glEnd();


    glColor3f(0.2745, 0.2274, 0.1960);
    glBegin(GL_LINES);
    glVertex3f(10.0, 0.0, 0.0);
    glVertex3f(10.0, 0.0, 50.0);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(20.0, 0.0, 0.0);
    glVertex3f(20.0, 0.0, 50.0);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(30.0, 0.0, 0.0);
    glVertex3f(30.0, 0.0, 50.0);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(40.0, 0.0, 0.0);
    glVertex3f(40.0, 0.0, 50.0);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(50.0, 0.0, 0.0);
    glVertex3f(50.0, 0.0, 50.0);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, 10.0);
    glVertex3f(50.0, 0.0, 10.0);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, 20.0);
    glVertex3f(50.0, 0.0,20.0);
    glEnd();


    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, 30.0);
    glVertex3f(50.0, 0.0, 30.0);
    glEnd();



    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, 40.0);
    glVertex3f(50.0, 0.0, 40.0);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, 50.0);
    glVertex3f(50.0, 0.0, 50.0);
    glEnd();

    // Draw the walls


    glColor3f(0.5, 0.5, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(50.0, 0.0, 0.0);
    glVertex3f(50.0, 40.0, 0.0);
    glVertex3f(0.0, 40.0, 0.0);
    glEnd();


    glColor3f(0.9, 0.9, 0.3);
    glBegin(GL_QUADS);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 50.0);
    glVertex3f(0.0, 40.0, 50.0);
    glVertex3f(0.0, 40.0, 0.0);
    glEnd();

    glColor3f(0.247, 0.165, 0.078);
    glBegin(GL_QUADS);
    glVertex3f(30.0, 0.0, 0.0);
    glVertex3f(30.0, 25.0, 0.0);
    glVertex3f(37.0, 25.0, 0.0);
    glVertex3f(37.0, 0.0, 0.0);
    glEnd();


    //TV

    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex3f(0.0, 20.5, 10.5);
    glVertex3f(0.0, 28.5, 10.5);
    glVertex3f(0.0, 28.5, 20.5);
    glVertex3f(0.0, 20.5, 20.5);
    glEnd();

    //Socket
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(0.0, 22.5, 6.5);
    glVertex3f(0.0, 24.5, 6.5);
    glVertex3f(0.0, 24.5, 8.5);
    glVertex3f(0.0, 22.5, 8.5);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(0.0, 23.0, 10.5);
    glVertex3f(0.0, 23.0, 8.5);
    glEnd();


    //Map thing
    // draw backrest
    glColor3f(0.5, 0.5, 0.5); // set color to gray
    glTranslatef(5.0, 10.0, 35.0); // move up
    glScalef(1.0, 2.0, 0.5); // scale in y and z directions
    glutSolidCube(6.0); // draw a cube

    // draw seat
    glColor3f(0.0, 0.0, 1.0); // set color to blue
    glTranslatef(0.0, -3.5, 0.0); // move down
    glScalef(2.0, 1, 2.0); // scale in y direction
    glutSolidCube(1.0); // draw a cube

    // draw legs
    glColor3f(0.0, 1.0, 0.0); // set color to green
    glTranslatef(-0.4, -0.5, -0.4); // move to bottom left corner
    glutSolidCube(1); // draw a cube
    glTranslatef(0.8, 0.0, 0.0); // move to bottom right corner
    glutSolidCube(1); // draw a cube
    glTranslatef(0.0, 0.0, 0.8); // move to top right corner
    glutSolidCube(1); // draw a cube
    glTranslatef(-0.8, 0.0, 0.0); // move to top left corner
    glutSolidCube(1); // draw a cube

    //Sofa
    glColor3f(0.031372, 0.56078, 0.56078); // set color to green
    glTranslatef(20, 1, 0); // move to bottom left corner
    glScalef(2.5, 6, 2);
    glutSolidCube(1); // draw a cube

    glTranslatef(0, 0, -15); // move to bottom left corner
    glutSolidCube(1); // draw a cube

    glColor3f(0.372549, 0.6196, 0.62745);
    glTranslatef(0, 0, 7.5);
    glScalef(1, 0.25, 15);
    glutSolidCube(1);

    glTranslatef(0.5, 2.5, 0);
    glScalef(0.5, 6, 1);
    glutSolidCube(1);


    glutSwapBuffers();

    drawStickman4();

    glFlush();
}

void displaybedroom()
{
    //PlaySound(NULL,NULL,0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0, 1.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(65.0,65.0,65.0, 20.0, 20.0, 20.0, 0.0, 1.0, 0.0);
    glRotatef(cameraAngleX, 1.0, 0.0, 0.0);
    glRotatef(cameraAngleY, 0.0, 1.0, 0.0);


    // Draw the floor
    glColor3f(0.6431, 0.4549, 0.2862);
    glBegin(GL_QUADS);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 50.0);
    glVertex3f(50.0, 0.0, 50.0);
    glVertex3f(50.0, 0.0, 0.0);
    glEnd();


    // Draw the walls

    glColor3f(1.0, 0, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 40.0, 0.0);
    glVertex3f(0.0, 40.0, 50.0);
    glVertex3f(0.0, 0.0, 50.0);
    glEnd();


    glColor3f(0.752941,0.752941,0.752941);
    glBegin(GL_QUADS);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 40.0, 0.0);
    glVertex3f(50.0, 40.0, 0.0);
    glVertex3f(50.0, 0.0, 0.0);
    glEnd();

    //Door
    glColor3f(0.247, 0.165, 0.078);
    glBegin(GL_QUADS);
    glVertex3f(0.0, 0.0, 45.0);
    glVertex3f(0.0, 20.0, 45.0);
    glVertex3f(0.0, 20.0, 35.0);
    glVertex3f(0.0, 0.0, 35.0);
    glEnd();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(0,10,42);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();



    //Socket
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex3f(0, 5.55, 0.55);
    glVertex3f(0, 3.55, 0.55);
    glVertex3f(0, 3.55, 3.55);
    glVertex3f(0, 5.55, 3.55);
    glEnd();

    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(0, 5.5, 0.5);
    glVertex3f(0, 3.5, 0.5);
    glVertex3f(0, 3.5, 3.5);
    glVertex3f(0, 5.5, 3.5);
    glEnd();

    //TV
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex3f(0, 25.0, 20.0);
    glVertex3f(0, 25.0, 28.0);
    glVertex3f(0, 18.0, 28.0);
    glVertex3f(0, 18.0, 20.0);
    glEnd();


    //Wire
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(0.0, 20.0, 20);
    glVertex3f(0.0, 20.0, 2);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(0.0, 20.0, 2);
    glVertex3f(0.0, 5.5, 2);
    glEnd();

    //Painting
    glColor3f(0.247, 0.165, 0.078);
    glBegin(GL_QUADS);
    glVertex3f(19.8, 25.2, 0.0);
    glVertex3f(19.8, 14.8, 0);
    glVertex3f(30.2, 14.8, 0);
    glVertex3f(30.2, 25.2, 0.0);
    glEnd();

    glColor3f(0.18039, 0.54509, 0.3411764);
    glBegin(GL_QUADS);
    glVertex3f(20, 25.0, 0.0);
    glVertex3f(20, 15.0, 0);
    glVertex3f(30, 15.0, 0);
    glVertex3f(30, 25.0, 0.0);
    glEnd();



    for(int i=5.0 ; i>=1.5; i--)
    {
        glColor3f(1.0, 0.0, 0.0);
        glPushMatrix();
        glTranslatef(25, 20.0, 0.0);
        glRotatef(0.0, 1.0, 0.0, 0.0);
        gluPartialDisk(gluNewQuadric(), i-0.5, i, 20, 1, 0.0, 180.0);
        glPopMatrix();

        glColor3f(1.0, 1.0, 1.0);
        glPushMatrix();
        glTranslatef(25, 20.0, 0.0);
        glRotatef(0.0, 1.0, 0.0, 0.0);
        gluPartialDisk(gluNewQuadric(), i-0.5, i, 20, 1, 0.0, -180.0);
        glPopMatrix();

        glColor3f(1.0, 1.0, 1.0);
        glPushMatrix();
        glTranslatef(25, 20.0, 0.0);
        glRotatef(0.0, 1.0, 0.0, 0.0);
        gluPartialDisk(gluNewQuadric(), i-1, i-0.5, 20, 1, 0.0, 180.0);
        glPopMatrix();


        glColor3f(0.0, 0.0, 1.0);
        glPushMatrix();
        glTranslatef(25, 20.0, 0.0);
        glRotatef(0.0, 1.0, 0.0, 0.0);
        gluPartialDisk(gluNewQuadric(), i-1, i-0.5, 20, 1, 0.0, -180.0);
        glPopMatrix();
    }

    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(25, 20.0, 0.0);
    glRotatef(0.0, 1.0, 0.0, 0.0);
    gluPartialDisk(gluNewQuadric(), 0.0, 1.0, 20, 1, 0.0, 360.0);
    glPopMatrix();

    glColor3f(0,0,0);
    glBegin(GL_LINE);
    glVertex3f(25.0, 29.0, 0.0);
    glVertex3f(19.8, 25.2, 0.0);
    glEnd();

    glBegin(GL_LINE);
    glVertex3f(25.0, 29.0, 0.0);
    glVertex3f(30.2, 25.2, 0.0);
    glEnd();


    // Draw the bed
    glColor3f(1, 1, 1); // White color for bed
    glPushMatrix();
    glTranslatef(35.0, 1.5, 25.0); // Position the bed
    glScalef(25, 3, 15); // Scale the bed
    glutSolidCube(1.0); // Draw the bed as a cuboid
    glPopMatrix();



    // Draw pillow
    glColor3f(0, 0.0, 1); // Red color for bed
    glPushMatrix();
    glTranslatef(45.0, 3.5, 25.0); // Position the bed
    glScalef(3, 2, 8); // Scale the bed
    glutSolidCube(1.0); // Draw the bed as a cuboid
    glPopMatrix();

        // Draw the bed
    glColor3f(0, 0.0, 1.0); // Red color for bed
    glPushMatrix();
    glTranslatef(28.0, 1.5, 25.0); // Position the bed
    glScalef(20.5, 3.5, 15.5); // Scale the bed
    glutSolidCube(1.0); // Draw the bed as a cuboid
    glPopMatrix();

    //Stickman
    // Draw head
    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(43.0, 3, 25.0);
    glutSolidSphere(2, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40.0, 3, 25.0);
    glScalef(10.0, 1.0, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(39.0, 3, 25.0);
    glScalef(1.0, 1.0, 9.0);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(35.5, 3, 25.0);
    glScalef(1.0, 1.0, 2.0);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(36.0, 3, 26.0);
    glScalef(9.0, 1.0, 1);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(36.0, 3, 24.0);
    glScalef(9.0, 1.0, 1);
    glutSolidCube(1.0);
    glPopMatrix();




    glutSwapBuffers();

    glFlush();
}

void displaykitchen()
{
    //PlaySound(NULL,NULL,0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(cameraX, cameraY, cameraZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glRotatef(cameraAngleX, 1.0, 0.0, 0.0);
    glRotatef(cameraAngleY, 0.0, 1.0, 0.0);


    // Draw the kitchen
    glBegin(GL_QUADS);

    // Floor
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-5, -0.5, -5);
    glVertex3f(5, -0.5, -5);
    glVertex3f(5, -0.5, 5);
    glVertex3f(-5, -0.5, 5);


    // Stove
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-1, -0.3, -3);
    glVertex3f(1, -0.3, -3);
    glVertex3f(1, 0.2, -3);
    glVertex3f(-1, 0.2, -3);

    // Table
    glColor3f(0.5, 0.2, 0);
    glVertex3f(-2, -0.5, 2);
    glVertex3f(2, -0.5, 2);
    glVertex3f(2, -0.5, -2);
    glVertex3f(-2, -0.5, -2);

    glColor3f(1, 1, 1);
    glVertex3f(-1, -0.5, 1);
    glVertex3f(1, -0.5, 1);
    glVertex3f(1, -0.5, -1);
    glVertex3f(-1, -0.5, -1);

// Ceiling light
    glColor3f(1, 1, 0.5);
    glVertex3f(-0.5, 6.0, -0.5);
    glVertex3f(-0.5, 6.0, 0.5);
    glVertex3f(0.5, 6.0, 0.5);
    glVertex3f(0.5, 6.0, -0.5);


    //Walls

    glColor3f(1, 1, 1);
    glVertex3f(-5, -0.5, -5);
    glVertex3f(-5, 3, -5);
    glVertex3f(-5, 3, 5);
    glVertex3f(-5, -0.5, 5);

    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-5, -0.5, 5);
    glVertex3f(-5, 3, 5);
    glVertex3f(5, 3, 5);
    glVertex3f(5, -0.5, 5);

    glVertex3f(-5, -0.5, -5);
    glVertex3f(-5, 3, -5);
    glVertex3f(5, 3, -5);
    glVertex3f(5, -0.5, -5);
    glColor3f(1, 1, 1);
    glVertex3f(5, -0.5, -5);
    glVertex3f(5, 3, -5);
    glVertex3f(5, 3, 5);
    glVertex3f(5, -0.5, 5);

    // Cabinets
    glColor3f(0.8, 0.7, 0.7);
    glVertex3f(-5, -0.5, -2.5);
    glVertex3f(-5, 1.5, -2.5);
    glVertex3f(-5, 1.5, -1.5);
    glVertex3f(-5, -0.5, -1.5);

    glColor4f(0.6, 0.4, 0.2, 1.0);
    glVertex3f(-5, -0.0, 1.5);
    glVertex3f(-5, 1.5, 1.5);
    glVertex3f(-5, 1.5, 2.5);
    glVertex3f(-5, -0.0, 2.5);

    glVertex3f(-5, -0.0, -0.2);
    glVertex3f(-5, 1.5, -0.2);
    glVertex3f(-5, 1.5, 0.8);
    glVertex3f(-5, -0.0, 0.8);


    const float PI = 3.14159265359;
    float radius = 0.3;
    int numSegments = 100;
    glColor3f(0.4,0.4,0.4);
    for (int i = 0; i < numSegments; ++i) {
        float theta1 = (float)i * 2.0 * PI / numSegments;
        float theta2 = (float)(i + 1) * 2.0 * PI / numSegments;
        glVertex3f(-0.2+radius * cos(theta1), 0.6, -3 + radius * sin(theta1));
        glVertex3f(-0.2+radius * cos(theta2), 0.6, -3 + radius * sin(theta2));
        glVertex3f(-0.2, 0.6, -3);
    }

    radius = 0.2;
    numSegments = 100;
    glColor3f(1.0,0.27,0.0);
    for (int i = 0; i < numSegments; ++i) {
        float theta1 = (float)i * 2.0 * PI / numSegments;
        float theta2 = (float)(i + 1) * 2.0 * PI / numSegments;
        glVertex3f(-0.2+radius * cos(theta1), 0.6, -3 + radius * sin(theta1));
        glVertex3f(-0.2+radius * cos(theta2), 0.6, -3 + radius * sin(theta2));
        glVertex3f(-0.2, 0.6, -3);
    }

    radius = 0.3;
    numSegments = 100;
    glColor3f(0.4,0.4,0.4);
    for (int i = 0; i < numSegments; ++i) {
        float theta1 = (float)i * 2.0 * PI / numSegments;
        float theta2 = (float)(i + 1) * 2.0 * PI / numSegments;
        glVertex3f(0.7+radius * cos(theta1), 0.6, -3 + radius * sin(theta1));
        glVertex3f(0.7+radius * cos(theta2), 0.6, -3 + radius * sin(theta2));
        glVertex3f(0.7, 0.6, -3);
    }

    radius = 0.2;
    numSegments = 100;
    glColor3f(1.0,0.27,0.0);
    for (int i = 0; i < numSegments; ++i) {
        float theta1 = (float)i * 2.0 * PI / numSegments;
        float theta2 = (float)(i + 1) * 2.0 * PI / numSegments;
        glVertex3f(0.7+radius * cos(theta1), 0.6, -3 + radius * sin(theta1));
        glVertex3f(0.7+radius * cos(theta2), 0.6, -3 + radius * sin(theta2));
        glVertex3f(0.7, 0.6, -3);
    }

    // Pizza (Circle)
    radius = 0.7;
    numSegments = 50;
    glColor3f(1.0, 0.6, 0.0);
    for (int i = 0; i < numSegments; ++i) {
        float theta1 = (float)i * 2.0 * PI / numSegments;
        float theta2 = (float)(i + 1) * 2.0 * PI / numSegments;
        glVertex3f(-2.8+radius * cos(theta1), -4, -3 + radius * sin(theta1)); // Update y-coordinate to -0.2 for placing on the table
        glVertex3f(-2.8+radius * cos(theta2), -4, -3 + radius * sin(theta2));
        glVertex3f(-2.8, -4, -3);
    }

    radius = 0.7;
    numSegments = 50;
    glColor3f(1.0, 0.6 ,0.0);
    for (int i = 0; i < numSegments; ++i) {
        float theta1 = (float)i * 2.0 * PI / numSegments;
        float theta2 = (float)(i + 1) * 2.0 * PI / numSegments;
        glVertex3f(-2.8+radius * cos(theta1), -4, -3 + radius * sin(theta1)); // Update y-coordinate to -0.2 for placing on the table
        glVertex3f(-2.8+radius * cos(theta2), -4, -3 + radius * sin(theta2));
        glVertex3f(-2.8, -4, -3);
    }
    radius = 0.6;
    numSegments = 50;
    glColor3f(1.0, 0.0, 0.0);
    for (int i = 0; i < numSegments; ++i) {
        float theta1 = (float)i * 2.0 * PI / numSegments;
        float theta2 = (float)(i + 1) * 2.0 * PI / numSegments;
        glVertex3f(-2.8+radius * cos(theta1), -4, -3 + radius * sin(theta1)); // Update y-coordinate to -0.2 for placing on the table
        glVertex3f(-2.8+radius * cos(theta2), -4, -3 + radius * sin(theta2));
        glVertex3f(-2.8, -4, -3);
    }
    glEnd();

    // Draw the stickman
    glColor3f(0.0, 0.0, 0.0); // Black color for stickman
    glTranslatef(0.0, -0.4, 0.0); // Translate to position of stickman's head
    glLineWidth(3.0); // Set line width for stickman's body parts

    // Draw stickman's head
    glBegin(GL_LINE_LOOP);
    radius = 0.15;
    for (float theta = 0; theta < 2 * PI; theta += 0.1) {
        float x = 3.3+radius * cos(theta);
        float y = 3.3+radius * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();

    // Draw stickman's body
    glBegin(GL_LINES);
    glVertex2f(0.0+3.3, 0.0+3.3); // Head to body
    glVertex2f(0.0+3.3, -0.7+3.3);
    glEnd();

    // Draw stickman's arms
    glBegin(GL_LINES);
    glVertex2f(0.0+3.3, -0.5+3.3); // Body to left arm
    glVertex2f(-0.3+3.3, -0.3+3.3);
    glVertex2f(0.0+3.3, -0.5+3.3); // Body to right arm
    glVertex2f(0.3+3.3, -0.3+3.3);
    glEnd();

    // Draw stickman's legs
    glBegin(GL_LINES);
    glVertex2f(0.0+3.3, -0.7+3.3); // Body to left leg
    glVertex2f(-0.3+3.3, -0.9+3.3);
    glVertex2f(0.0+3.3, -0.7+3.3); // Body to right leg
    glVertex2f(0.3+3.3, -0.9+3.3);
    glEnd();

    // Draw four legs for the table
    drawTableLeg(1, -2, -3.5, 0.1, 0.6);
    drawTableLeg(-3.3, -2, 0.8, 0.1, 0.6);
    drawTableLeg(0.8, -2, 0.8, 0.1, 0.6);

    glutSwapBuffers();


    drawStickman4();

    glFlush();
}

void displayarmory()
{
    //PlaySound(NULL,NULL,0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(4.0,4.0,4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glRotatef(cameraAngleX, 1.0, 0.0, 0.0);
    glRotatef(cameraAngleY, 0.0, 1.0, 0.0);

    // Draw walls
    glColor3f(0.8, 0.8, 0.8); // Light gray
    glBegin(GL_QUADS);
    glVertex3f(-2.0, -1.0, -2.0);
    glVertex3f(-2.0, 1.0, -2.0);
    glVertex3f(2.0, 1.0, -2.0);
    glVertex3f(2.0, -1.0, -2.0);


    glColor3f(0.81, 0.81, 0.81);
    glVertex3f(-2.0, -1.0, 2.0);
    glVertex3f(-2.0, 1.0, 2.0);
    glVertex3f(2.0, 1.0, 2.0);
    glVertex3f(2.0, -1.0, 2.0);


    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-2.0, -1.0, -2.0);
    glVertex3f(-2.0, 1.0, -2.0);
    glVertex3f(-2.0, 1.0, 2.0);
    glVertex3f(-2.0, -1.0, 2.0);


    glColor3f(0.81, 0.81, 0.81);
    glVertex3f(2.0, -1.0, -2.0);
    glVertex3f(2.0, 1.0, -2.0);
    glVertex3f(2.0, 1.0, 2.0);
    glVertex3f(2.0, -1.0, 2.0);
    glEnd();

    // Draw floor
    glColor3f(0.5, 0.5, 0.5); // Dark gray
    glBegin(GL_QUADS);
    glVertex3f(-2.0, -1.0, -2.0);
    glVertex3f(-2.0, -1.0, 2.0);
    glVertex3f(2.0, -1.0, 2.0);
    glVertex3f(2.0, -1.0, -2.0);
    glEnd();

    //Door
    glColor3f(0.247, 0.165, 0.078);
    glBegin(GL_QUADS);
    glVertex3f(2, 0.5, 0.0);
    glVertex3f(2, 0.5, -1.0);
    glVertex3f(2, -1.0, -1.0);
    glVertex3f(2, -1.0, 0.0);
    glEnd();

    //Door
    glColor3f(0.247, 0.165, 0.078);
    glBegin(GL_QUADS);
    glVertex3f(-2, 0.5, 0.0);
    glVertex3f(-2, 0.5, -1.0);
    glVertex3f(-2, -1.0, -1.0);
    glVertex3f(-2, -1.0, 0.0);
    glEnd();




    // Draw Shield
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex3f(-0.5,0.5, 2);
    glVertex3f(-0.1,0.75, 2);
    glVertex3f(0.1,0.75, 2);
    glVertex3f(0.5,0.5, 2);
    glVertex3f(0,-0.5, 2);
    glEnd();


    // Draw Flag
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 1);
    glVertex3f(-0.2,0.5, -2);
    glVertex3f(-0.15,-0.2, -2);
    glVertex3f(0.0,-0.15, -2);
    glVertex3f(0.15,-0.2, -2);
    glVertex3f(0.2,0.5, -2);
    glEnd();


    // Draw table
    glColor3f(0.8, 0.4, 0.0); // Dark orange
    glBegin(GL_QUADS);
    glVertex3f(-0.5, -0.8, -0.5);
    glVertex3f(-0.5, -0.8, 0.5);
    glVertex3f(0.5, -0.8, 0.5);
    glVertex3f(0.5, -0.8, -0.5);
    glEnd();



    // Draw table
    glPushMatrix();
    glTranslatef(0.0, -0.6, 0.0);
    glRotatef(0.0, 0.0, 1.0, 0.0);
    glColor3f(0.3, 0.3, 0.3); // Dark gray
    glScalef(0.5, 0.5, 1);
    glutSolidCube(1);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, -0.3, 0.0);
    glRotatef(0.0, 0.0, 1.0, 0.0);
    glColor3f(1, 0, 0); // Dark gray
    //glScalef(0.5, 0.5, 1);
    glutSolidCube(0.1);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5, 0, 1.5);
    glRotatef(0.0, 0.0, 1.0, 0.0);
    glColor3f(0.9, 0.9, 0.9);
    glScalef(1.5, 2, 1);
    glutSolidCube(0.75);
    glEnd();
    glPopMatrix();


    glutSwapBuffers();


    glFlush();
}

void displaywater()
{
    //PlaySound(NULL,NULL,0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(4.0,4.0,4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glRotatef(cameraAngleX, 1.0, 0.0, 0.0);
    glRotatef(cameraAngleY, 0.0, 1.0, 0.0);

    // Draw walls and floor of the room
    glColor3f(0.296f, 0.263f, 0.129f);

    glBegin(GL_QUADS);
    // Front wall
    glVertex3f(-2.0, -1.0, -2.0);
    glVertex3f(-2.0, 1.0, -2.0);
    glVertex3f(2.0, 1.0, -2.0);
    glVertex3f(2.0, -1.0, -2.0);
    // Back wall
    glVertex3f(-2.0, -1.0, 2.0);
    glVertex3f(-2.0, 1.0, 2.0);
    glVertex3f(2.0, 1.0, 2.0);
    glVertex3f(2.0, -1.0, 2.0);
    // Left wall
    glColor3f(0.396f, 0.163f, 0.129f);

    glVertex3f(-2.0, -1.0, -2.0);
    glVertex3f(-2.0, 1.0, -2.0);
    glVertex3f(-2.0, 1.0, 2.0);
    glVertex3f(-2.0, -1.0, 2.0);
    // Right wall
    glVertex3f(2.0, -1.0, -2.0);
    glVertex3f(2.0, 1.0, -2.0);
    glVertex3f(2.0, 1.0, 2.0);
    glVertex3f(2.0, -1.0, 2.0);
    // Floor
    glColor3f(0.396f, 0.263f, 0.129f);

    glVertex3f(-2.0, -1.0, -2.0);
    glVertex3f(2.0, -1.0, -2.0);
    glVertex3f(2.0, -1.0, 2.0);
    glVertex3f(-2.0, -1.0, 2.0);
    glEnd();


    //DRaw pipe line
    glPushMatrix();
    glColor3f(0.898039, 0.894117, 0.88627); // Gray
    glTranslatef(0.0, 0.75 , 0.0);
    glScalef(0.1,3   ,0.1);
    glutSolidCube(0.5); // Draw cube as air purifier
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.898039, 0.894117, 0.88627); // Gray
    glTranslatef(1, 0.25 , 0);
    glScalef(0.1, 4   ,0.1);
    glutSolidCube(0.5); // Draw cube as air purifier
    glPopMatrix();



    // Draw a blue water purifier
    glPushMatrix();
    glColor3f(0.0, 0.0, 1.0); // Blue
    glTranslatef(0.0, -0.5, 0.0); // Move down to the floor
    glutSolidSphere(0.5, 20, 20); // Draw sphere as water purifier
    glTranslatef(0.0, 0.5, 0.0);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();

    // Draw a gray air purifier
    glPushMatrix();
    glColor3f(0.443137, 0.4745098, 0.494117); // Gray
    glTranslatef(1.0, -0.5, 0.0);
    glScalef(1,2,1);
    glutSolidCube(0.5); // Draw cube as air purifier
    glPopMatrix();

    // Draw a green plant
    glPushMatrix();
    glTranslatef(-1.5, -1, -1);
    glColor3f(0, 0.6, 0);
    glRotatef(-90, 1.0, 0.0, 0.0);
    glutSolidCone(0.3, 1, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.5, -1, 0);
    glColor3f(0, 0.6, 0);
    glRotatef(-90, 1.0, 0.0, 0.0);
    glutSolidCone(0.3, 1, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.5, -1, 1);
    glColor3f(0, 0.6, 0);
    glRotatef(-90, 1.0, 0.0, 0.0);
    glutSolidCone(0.3, 1, 10, 10);
    glPopMatrix();

    glutSwapBuffers();
    glFlush();
}

void displaycropr()
{
    //PlaySound(NULL,NULL,0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(4.0,4.0,4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glRotatef(cameraAngleX, 1.0, 0.0, 0.0);
    glRotatef(cameraAngleY, 0.0, 1.0, 0.0);


    // Draw the scene
    glBegin(GL_QUADS);


    // Floor
    glColor3f(0.396f, 0.263f, 0.129f);
    glVertex3f(-2, 0, -2);
    glVertex3f(2, 0, -2);
    glVertex3f(2, 0, 2);
    glVertex3f(-2, 0, 2);

    // Shelf
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-1.5, 0.5, -1.5);
    glVertex3f(1.5, 0.5, -1.5);
    glVertex3f(1.5, 0.5, -0.5);
    glVertex3f(-1.5, 0.5, -0.5);

    glVertex3f(-1.5, 0.75, -1.5);
    glVertex3f(1.5, 0.75, -1.5);
    glVertex3f(1.5, 0.75, -0.5);
    glVertex3f(-1.5, 0.75, -0.5);

    glVertex3f(-1.5, 0.5, -1.5);
    glVertex3f(-1.5, 0.75, -1.5);
    glVertex3f(-1.5, 0.75, -0.5);
    glVertex3f(-1.5, 0.5, -0.5);

    glVertex3f(1.5, 0.5, -1.5);
    glVertex3f(1.5, 0.75, -1.5);
    glVertex3f(1.5, 0.75, -0.5);
    glVertex3f(1.5, 0.5, -0.5);

    glEnd();

// Draw some plants
    glPushMatrix();
    glTranslatef(-1.5, 0, -1);
    glColor3f(0, 0.6, 0);
    glRotatef(-90, 1.0, 0.0, 0.0);
    glutSolidCone(0.3, 1, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.5, 0, -1);
    //glColor3f(0.6, 0, 0);
    glRotatef(-90, 1.0, 0.0, 0.0);
    glutSolidCone(0.3, 1, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5, 0, -1);
    //glColor3f(0, 0, 0.6);
    glRotatef(-90, 1.0, 0.0, 0.0);
    glutSolidCone(0.3, 1, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.5, 0, 0);
    glColor3f(0, 0.6, 0);
    glRotatef(-90, 1.0, 0.0, 0.0);
    glutSolidCone(0.3, 1, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.5, 0, 0);
    //glColor3f(0.6, 0, 0);
    glRotatef(-90, 1.0, 0.0, 0.0);
    glutSolidCone(0.3, 1, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5, 0, 0);
    //glColor3f(0, 0, 0.6);
    glRotatef(-90, 1.0, 0.0, 0.0);
    glutSolidCone(0.3, 1, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5, 0, 1);
    //glColor3f(0, 0, 0.6);
    glRotatef(-90, 1.0, 0.0, 0.0);
    glutSolidCone(0.3, 1, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.5, 0, 1);
    glColor3f(0, 0.6, 0);
    glRotatef(-90, 1.0, 0.0, 0.0);
    glutSolidCone(0.3, 1, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.5, 0, 1);
    //glColor3f(0.6, 0, 0);
    glRotatef(-90, 1.0, 0.0, 0.0);
    glutSolidCone(0.3, 1, 10, 10);
    glPopMatrix();

    glutSwapBuffers();

    drawStickman4();

    glFlush();
}

void mouse3(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)   // if the left mouse button is clicked
    {
        //Button for return
        if (x >=1420 && x <= 1520 && y >= 600 && y <= 700)  // if the click is within the button
        {
            glutDestroyWindow(window3);
            //glutInitWindowSize(600, 600); // set the window size
            window1 = glutCreateWindow("Underground Bunker"); // create a new window with the specified title
            glutFullScreen();
            glutDisplayFunc(display3); // set the display function for the new window
            glutMouseFunc(mouse2);
        }
    }

}

void mouse2(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)   // if the left mouse button is clicked
    {
        //Button for main room
        if (x >= 530 && x <= 780 && y >= 260 && y <= 390)  // if the click is within the button
        {
            glutDestroyWindow(window3);
            window4 = glutCreateWindow("Main Room"); // create a new window with the specified title
            glutFullScreen();
            glutDisplayFunc(display4); // set the display function for the new window
            PlaySound("vert.wav",NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
            glutReshapeFunc(reshape);
            glutKeyboardFunc(mykey);
        }
        //Button for Water and air
        if (x >= 245 && x <= 475 && y >= 360 && y <= 465)  // if the click is within the button
        {
            glutDestroyWindow(window3);
            window4 = glutCreateWindow("Water and Air purifier"); // create a new window with the specified title
            glutFullScreen();
            glutDisplayFunc(displaywater); // set the display function for the new window
            PlaySound(NULL,NULL,0);
            glutReshapeFunc(reshape);
            glutKeyboardFunc(mykey);
        }
        //Button for Bedroom
        if (x >= 895 && x <= 1130 && y >= 260 && y <= 390)  // if the click is within the button
        {
            glutDestroyWindow(window3);
            window4 = glutCreateWindow("Bedroom"); // create a new window with the specified title
            glutFullScreen();
            glutDisplayFunc(displaybedroom); // set the display function for the new window
            PlaySound("bedroom.wav",NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
            glutReshapeFunc(reshape);
            glutKeyboardFunc(mykey);
        }

        //Button for Kitchen
        if (x >= 590 && x <= 845 && y >= 440 && y <= 567)  // if the click is within the button
        {
            glutDestroyWindow(window3);
            window4 = glutCreateWindow("Kitchen"); // create a new window with the specified title
            glutFullScreen();
            glutDisplayFunc(displaykitchen); // set the display function for the new window
            PlaySound("kitchen.wav",NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
            glutReshapeFunc(reshape);
            glutKeyboardFunc(mykey1);
        }

        //Button for Food crops
        if (x >= 230 && x <= 475 && y >= 555 && y <= 683)  // if the click is within the button
        {
            glutDestroyWindow(window3);
            window4 = glutCreateWindow("Food crops"); // create a new window with the specified title
            glutFullScreen();
            glutDisplayFunc(displaycropr); // set the display function for the new window
            PlaySound(NULL,NULL,0);
            glutReshapeFunc(reshape);
            glutKeyboardFunc(mykey);
        }

        //Button for Emergency room
        if (x >= 718 && x <= 1155 && y >= 670 && y <= 783)  // if the click is within the button
        {
            glutDestroyWindow(window3);
            window4 = glutCreateWindow("Armory"); // create a new window with the specified title
            glutFullScreen();
            glutDisplayFunc(displayarmory); // set the display function for the new window
            PlaySound(NULL,NULL,0);
            glutReshapeFunc(reshape);
            glutKeyboardFunc(destruct);
        }

        //Button for return
        if (x >=1420 && x <= 1520 && y >= 700 && y <= 800)  // if the click is within the button
        {
            glutDestroyWindow(window3);
            window1 = glutCreateWindow("Underground Bunker"); // create a new window with the specified title
            glutFullScreen();
            glutDisplayFunc(display2); // set the display function for the new window
            glutMouseFunc(mouse1);
        }
    }
}

void mouse1(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)   // if the left mouse button is clicked
    {
        //Button for main room
        if (x >= 530 && x <= 780 && y >= 260 && y <= 390)  // if the click is within the button
        {
            glutDestroyWindow(window2);
            window3 = glutCreateWindow("Main Room"); // create a new window with the specified title
            glutFullScreen();
            glutDisplayFunc(display3); // set the display function for the new window
            glutMouseFunc(mouse2);
        }
        //Button for Kitchen
        if (x >= 590 && x <= 845 && y >= 440 && y <= 567)  // if the click is within the button
        {
            glutDestroyWindow(window3);
            window4 = glutCreateWindow("Kitchen"); // create a new window with the specified title
            glutFullScreen();
            glutDisplayFunc(displaykitchen); // set the display function for the new window
            PlaySound("kitchen.wav",NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
            glutReshapeFunc(reshape);
            glutKeyboardFunc(mykey1);
        }


        //Button for Bedroom
        if (x >= 895 && x <= 1130 && y >= 260 && y <= 390)  // if the click is within the button
        {
            glutDestroyWindow(window3);
            window4 = glutCreateWindow("Bedroom"); // create a new window with the specified title
            glutFullScreen();
            glutDisplayFunc(displaybedroom); // set the display function for the new window
            PlaySound("bedroom.wav",NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
            glutReshapeFunc(reshape);
            glutKeyboardFunc(mykey);
        }

        //Button for Water and air
        if (x >= 245 && x <= 475 && y >= 360 && y <= 465)  // if the click is within the button
        {
            glutDestroyWindow(window3);
            window4 = glutCreateWindow("Water and air purifier"); // create a new window with the specified title
            glutFullScreen();
            glutDisplayFunc(displaywater); // set the display function for the new window
            PlaySound(NULL,NULL,0);
            glutReshapeFunc(reshape);
            glutKeyboardFunc(mykey);
        }



        //Button for Emergency room
        if (x >= 718 && x <= 1155 && y >= 670 && y <= 783)  // if the click is within the button
        {
            glutDestroyWindow(window3);
            window4 = glutCreateWindow("Armory"); // create a new window with the specified title
            glutFullScreen();
            glutDisplayFunc(displayarmory); // set the display function for the new window
            //glutMouseFunc(mouse3);
            PlaySound(NULL,NULL,0);
            glutReshapeFunc(reshape);
            glutKeyboardFunc(destruct);
        }

        //Button for Food crops
        if (x >= 230 && x <= 475 && y >= 555 && y <= 683)  // if the click is within the button
        {
            glutDestroyWindow(window3);
            window4 = glutCreateWindow("Food crops"); // create a new window with the specified title
            glutFullScreen();
            glutDisplayFunc(displaycropr); // set the display function for the new window
            PlaySound(NULL,NULL,0);
            glutReshapeFunc(reshape);
            glutKeyboardFunc(mykey);
        }


        //Button for return
        if (x >=1420 && x <= 1520 && y >= 700 && y <= 800)  // if the click is within the button
        {
            glutDestroyWindow(window3);
            window1 = glutCreateWindow("Underground Bunker"); // create a new window with the specified title
            glutFullScreen();
            init();
            glutDisplayFunc(display1); // set the display function for the new window
            glutMouseFunc(mouse);
            glutKeyboardFunc(mykey1);
        }
    }
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)   // if the left mouse button is clicked
    {
        if (x >= 640 && x <= 820 && y >= 700 && y <= 780)  // if the click is within the button
        {
            glutDestroyWindow(window1);
            window2 = glutCreateWindow("New Window"); // create a new window with the specified title
            glutFullScreen();
            glutDisplayFunc(display2); // set the display function for the new window
            glutMouseFunc(mouse1);
        }
    }
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
}

void mykey(unsigned char key,int x,int y)
{
    switch (key)
    {
    case 'q':
        glutDestroyWindow(window4); // Close the first window
        window3=glutCreateWindow("Underground Bunker"); // create a new window with the specified title
        glutFullScreen();
        glutDisplayFunc(display3); // set the display function for the new window
        glutMouseFunc(mouse2);
        break;
    case 27:// ESC key
        exit(0);
        break;
    case 'a':
        cameraAngleY -= 5.0;
        break;
    case 'd':
        cameraAngleY += 5.0;
        break;
    case 'w':
        cameraAngleX -= 5.0;
        break;
    case 's':
        cameraAngleX += 5.0;
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

void mykey1(unsigned char key,int x,int y)
{
    switch (key)
    {
    case 'q':
        glutDestroyWindow(window4); // Close the first window
        window3=glutCreateWindow("Underground Bunker"); // create a new window with the specified title
        glutFullScreen();
        glutDisplayFunc(display3); // set the display function for the new window
        glutMouseFunc(mouse2);
        break;
    case 27:
        exit(0);
        break;
    }
    glutPostRedisplay();
}

void destruct(unsigned char key,int x,int y)
{
    switch (key)
    {
        case 'q':
        glutDestroyWindow(window4); // Close the first window
        window3=glutCreateWindow("Underground Bunker"); // create a new window with the specified title
        glutFullScreen();
        glutDisplayFunc(display3); // set the display function for the new window
        glutMouseFunc(mouse2);
        break;
    case 'x':
        glutDestroyWindow(window4); // Close the first window
        window3=glutCreateWindow("GameOver"); // create a new window with the specified title
        init();
        glutFullScreen();
        glutDisplayFunc(gameover); // set the display function for the new window
        PlaySound("bomb.wav",NULL, SND_FILENAME | SND_ASYNC);
        glutKeyboardFunc(exitkey);
        break;
    case 27:
        exit(0);
        break;
    case 'a':
        cameraAngleY -= 5.0;
        break;
    case 'd':
        cameraAngleY += 5.0;
        break;
    case 'w':
        cameraAngleX -= 5.0;
        break;
    case 's':
        cameraAngleX += 5.0;
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

void exitkey(unsigned char key,int x,int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;
    }
    glutPostRedisplay();
}

