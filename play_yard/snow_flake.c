// Koch Snowflake
// This program draws a snowflake with OpenGL.
//
// Copyright 2010 Samuel Pauls
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see .

// To compile: gcc main.c -lglut -Wall -std=c99

#include <stdlib.h> // EXIT_SUCCESS, malloc, free
#include <math.h> // cos, sin, pow

// OpenGL is an API specification that hardware manufacturers can implement to
// provide a standard interface for programmers to use their 3D acceleration
// capabilities.  Unlike "GL3/gl3.h," the following includes even deprecated
// functionality.
#include <GL/gl.h>

// GLUT, the OpenGL Utility Toolkit, provides features such as:
// - Generic window management
// - Generic input detection
// - Several 3D objects
#include <GL/glut.h>

// Snowflake Data
static const int ITERATIONS = 8;
static GLfloat *vertices;

// Creates a centered Koch Snowflake of unit length.
// See http://en.wikipedia.org/wiki/Koch_snowflake for details.
// Remember to manually free its memory after use.
GLfloat *createSnowflake (void) {
  static const GLfloat PI = 3.14159265358979323846; // not part of C99 standard
  int sides;
  GLfloat *vertices;

  // Create the first iteration, a centered equilateral triangle.
  sides = 3;
  vertices = malloc (sides * 2 * sizeof (GLfloat));
  GLfloat height = sin (PI / 3.0F);
  vertices[0] = -0.5F;
  vertices[1] = -height * 0.25F;
  vertices[2] = 0.5F;
  vertices[3] = vertices[1];
  vertices[4] = 0.0F;
  vertices[5] = height * 0.75F;

  // Add any further iterations, which are equilateral triangles sharing one
  // side with the middle third of each existing side of the snowflake.
  //
  // Calculate the ratio of a side's length to its normal's length, using
  // basic trigonometry.  Tan (30 deg) = nlen / (slen / 2).  If we set the
  // side's length to 1, the normal's length is a percentage of the side's
  // length.
  GLfloat nlen = tan (PI / 6.0F) * 1.0F / 2.0F;
  //
  for (int i = 1; i < ITERATIONS; ++i) {
    GLfloat *newVertices = malloc (sides * 2 * 4 * sizeof (GLfloat));

    // For each of the triangle's existing sides...
    int newI = 0;
    for (int s = 0; s < sides * 2; s += 2) {
      // Acquire the side's end points.
      GLfloat ax = vertices[s];
      GLfloat ay = vertices[s + 1];
      GLfloat bx = vertices[(s + 2) % (sides * 2)]; // wrap to first point
      GLfloat by = vertices[(s + 3) % (sides * 2)];

      // Calculate the deltas of the end points.
      GLfloat dx = bx - ax;
      GLfloat dy = by - ay;

      // Calculate two midpoints of the side.
      GLfloat m1x = ax + dx / 3.0F;
      GLfloat m1y = ay + dy / 3.0F;
      GLfloat m2x = ax + dx / 3.0F * 2.0F;
      GLfloat m2y = ay + dy / 3.0F * 2.0F;

      // Calculate the side's normal's direction.
      GLfloat nx = dy;
      GLfloat ny = -dx;

      // Set the normal's magnitude.
      nx *= nlen;
      ny *= nlen;

      // Move the normal to where it extends from the side.
      nx += (bx + ax) / 2.0F;
      ny += (by + ay) / 2.0F;

      // Create new vertices for the old side.
      newVertices[newI++] = vertices[s];
      newVertices[newI++] = vertices[s + 1];
      newVertices[newI++] = m1x;
      newVertices[newI++] = m1y;
      newVertices[newI++] = nx;
      newVertices[newI++] = ny;
      newVertices[newI++] = m2x;
      newVertices[newI++] = m2y;
    }

    // Replace the old vertices with the new ones from this iteration.
    free (vertices);
    vertices = newVertices;

    sides *= 4;
  }

  return vertices;
}

// Display the previously initialized Koch Snowflake.
void display (void) {
  glClear (GL_COLOR_BUFFER_BIT);

  // Draw the snowflake.
  glBegin (GL_LINE_LOOP);
    for (int i = 0; i < 3 * pow (4, ITERATIONS - 1) * 2; i += 2) {
      glVertex2f (vertices[i], vertices[i + 1]);
    }
  glEnd();

  glFlush();
}

int main (int argc, char **argv) {
  // Initialization
  glutInit (&argc, argv);
  glutInitWindowSize (800, 600);
  glutCreateWindow ("Snowflake");
  glClearColor (0.0F, 0.0F, 0.0F, 0.0F);
  glColor3f (0.5F, 0.5F, 1.0F);
  vertices = createSnowflake();
  // Display is called immediately and when the window is invalidated, which can
  // occur if a portion was previously off screen.
  glutDisplayFunc (display);

  glutMainLoop(); // never returns

  // Termination
  free (vertices); // for thoroughness
  return EXIT_SUCCESS; // prevent warning
}
