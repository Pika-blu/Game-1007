// Pseudo code for movement using vectors & jump with gravity
/*
y+
5|
4|
3|
2|
1|M____________________________ x+
0 1 2 3 4 5 6 7 8 9 10
vector 2 position = (0,0)
vertor2 velocity = (0,0)
vector2 gravity = (0,9-8)

float deltaTime = 1/fps 

updateFrame()
{
	if(keydown(rightArrow))
	  velocity.x = (+10 * deltaTime); // move right
	if(keydown(leftArrow))
	  velocity.x = (-10 * deltaTime); // move right


	if(playerIsOnGround)
	{
		if (keydown(spacebar))
			velocity.y = 20 * deltaTime // jump
    }
	else 
		velocity.y = velocity.y + gravity.y * deltaTime; // apply gravity

Notes about vectors
--scalar values--
distance = how far you have gone = 100
speed = distance/time

vector values
displacement = position = direction and distance from a reference point
velocity = change in displacement/ time
acceleration = change in velocity/time


vector (x,y) multiply this by scalar value n
result is the vectore (x*n,y*n)

(2,5) *4 = (8,20)

vector (x,y) * (n,m)
result is (x*n,y*m)
(2,4) * (5,3) = (10,12)

vector (x,y) + (n,m)
(x+n,y+m)
 same with subtration 

 length (magnitude) of (x,y)
 sqrt ( x^2+y^2)
 len(3,4) = sqrt(9+16) = 5

 normalize the vector
 (x,y) / len(x,y)
 (3,4) / 5 = (0.6,0.8)
 




/**