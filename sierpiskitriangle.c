#include "FPToolkit.c"

//use recursion to find the triangle given 3 points G_triangle (10, 300,  40,300,  60,250) ;
//Use the fill to fill in the triangle
//use lines initally



void calculateTriangle(double p1[],double p2[], double p3[],int depth) {

	if (depth == 0) 
		return;
	depth -= 1; //subtract from depth

	double midpoint1[2],midpoint2[2],midpoint3[2];//midpoints

	//Draw the triangle		k
	G_line(p1[0],p1[1], p2[0] ,p2[1] );	
	G_line(p1[0],p1[1], p3[0],p3[1]);
	G_line(p2[0],p2[1],p3[0],p3[1]);

	//calculate the mid point of p1 and p2
	midpoint1[0] =  (p2[0] +p1[0])/2;
	midpoint1[1] = (p2[1] + p1[1])/2;
	//clculate the midpoint of p1 and p3
	midpoint2[0] = (p1[0] + p3[0])/2;
	midpoint2[1] = (p1[1] + p3[1])/2;
	//calculate the midpoint of p2 and p3
	midpoint3[0] = (p2[0] + p3[0])/2;
	midpoint3[1] = (p2[1] + p3[1])/2;
	


	
	//check to make sure thats correct
//	G_fill_circle(midpoint2[0],midpoint2[1],3);
//	G_fill_circle(midpoint1[0],midpoint1[1],7); 
//	G_fill_circle(midpoint3[0],midpoint3[1],3);

	//Now sub divide into three diffrent ones
	calculateTriangle(midpoint1,p2,midpoint3,depth);
	calculateTriangle(p1,midpoint1,midpoint2,depth);
	calculateTriangle(midpoint2,midpoint3,p3,depth);
	

} 
int main() {
	
	double width = 10000;
	double height = 10000;
	double p1[2],p2[2],p3[2];

	int depth = 0;	
		
	printf("Enter in the depth of the fractal");
	scanf("%d", &depth);	
	printf("now select three points");


	G_init_graphics(width,height) ;
	
	//wait for clicks and draw	
	while(1) {	
		G_wait_click(p1);
		G_wait_click(p2);
		G_wait_click(p3);

	
		calculateTriangle(p1,p2,p3,depth);
	}

	G_wait_key() ;

}

