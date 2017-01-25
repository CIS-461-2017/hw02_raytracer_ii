#pragma once

#include <QRunnable>
#include <raytracing/film.h>
#include <raytracing/integrator.h>
#include <la.h>

class RenderTask : public QRunnable
{
public:
	RenderTask(glm::ivec2 min, glm::ivec2 max, Camera* c, Film* f, Integrator* i)
	: camera(c), film(f), integrator(i), minPixel(min), maxPixel(max)
	{}

	void run(); // A function declared in the QRunnable class that we must implement
				// in order for our class to be compatible with a QThreadPool.
				// This function should iterate over all the pixels this RenderTask
				// is supposed to handle and trace a ray through each of them, then 
				// set the pixel of the film to the correct color.

private:
	Camera const * const camera;			// A pointer to the Camera instance stored in MyGL.
	Film const * const film;				// A pointer to the Film instance stored in MyGL.
	Integrator const * const integrator; 	// A pointer to the Integrator instance stored in MyGL
											// You may need to const-ify a few functions in these classes
											// in order to use these pointers as necessary.

	const glm::ivec2 minPixel;				// The upper-left pixel of the screen portion this RenderTask handles
	const glm::ivec2 maxPixel;				// The lower-right pixel of the screen portion this RenderTask handles
};