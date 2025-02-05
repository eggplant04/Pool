# Tutorial – Static and Dynamic Rigid Bodies 
 
## Introduction and Objective: 
By now you should have a physics simulation that will detect and respond to collisions between dynamic rigid bodies. But when creating a game or simulation, not every physics object will need to move. 

Often, we’ll want to use static objects for walls, floors, or other physical objects that won’t move but will still need to respond to physics events.  

We could give these objects a very large mass (after all, that’s what would happen in the real world). But this means there is no difference between our ‘static’ and dynamic objects – all our static objects would do all the update processing to calculate their new position each frame, even though they never move! 

By updating our physics engine to allow us to explicitly specify static rigid bodies we can optimise not only the update function of these physics objects, but also the collision response processing for interactions between dynamic and static bodies. 

In this tutorial we’ll add the isKinematic variable to the RigidBody class to allow our simulation to have both static and dynamic rigid bodies. 
 
## Prerequisites:
We will be using the DIY Physics engine that you have been writing.
Ensure you have completed the following tutorials:
- ***Tutorial 01 - Fixed Timestep*** – *a version is also available in the* ***Create a Physics Engine - Fixed Timestep*** *Tutorial page on canvas.*
- ***Tutorial 02 - Linear Force & Momentum*** – *a version is also available in the* ***Create a Physics Engine - Linear Force & Momentum session*** *Tutorial page on canvas.*
- ***Tutorial 03 - Collision Detection*** – *a version is also available in the*  ***Create a Physics Engine - Collision Detection*** *Tutorial page on canvas.*
- ***Tutorial 04 - Collision Resolution Part 1*** – *a version is also available in the*  ***Create a Physics Engine - Collision Resolution*** *Presentation page on canvas.*
- ***Tutorial 04 - Collision Resolution Part 2*** – *a version is also available in the*  ***Create a Physics Engine - Sphere to Sphere Collisions*** *Presentation page on canvas.*
- ***Tutorial 04 - Collision Resolution Part 3*** – *a version is also available in the*  ***Create a Physics Engine - Sphere to Plane Collisions*** *Presentation page on canvas.*
- ***Tutorial 05 - Rotational Force Part 1*** – *a version is also available in the*  ***Create a Physics Engine - Torque*** *Presentation page on canvas.*
- ***Tutorial 05 - Rotational Force Part 2*** – *a version is also available in the*  ***Create a Physics Engine - Torque*** *Presentation page on canvas.*
- ***Tutorial 06 - Collision Response Static and Dynamic Friction*** – *a version is also available in the*  ***Create a Physics Engine - Static and Dynamic Friction*** *Presentation page on canvas.*
- ***Tutorial 07 - Contact Forces*** – *a version is also available in the*  ***Create a Physics Engine - Contact Forces*** *Tutorial page on canvas.*

Although recommended, it is not necessary to have completed the following previous tutorials:
- ***Tutorial 03.1 - Projectile Physics Part 1*** – *a version is also available in the*  ***Things You Should Know - Projectile Physics 1*** *Presentation page on canvas.*
- ***Tutorial 03.1 - Projectile Physics Part 2*** – *a version is also available in the*  ***Things You Should Know - Projectile Physics 2*** *Presentation page on canvas.*

## The Rigidbody Class: 
To start, we’ll add the isKinematic Boolean variable to the Rigidbody class: 

```c++
class Rigidbody : public PhysicsObject 
{ 
public: 
    ...
    ... 
    void SetKinematic(bool state) { m_isKinematic = state; } 
    bool IsKinematic() { return m_isKinematic; } 
    ...
    ... 
 
protected: 
    ...
    ... 
    bool m_isKinematic; 
};
```

Ensure the variable is initialized to false in the *Rigidbody* class constructors. Whenever the *isKinematic* variable is true, this means that the rigidbody is kinematic (i.e., its static 
and will not move in response to collisions). In game engines, the term kinematic object is used to refer to those objects that are user controlled. Kinematic objects do not change their position dynamically in response to the physical simulation. However, the user (i.e., us) can still change the position of the object directly by modifying its variables  directly. The object will also still interact with other dynamic physics objects in the simulation. 

Because we don’t need to modify a static object’s position in response to collisions, for static objects we can simply skip everything inside the *FixedUpdate()* function. 

```c++
void Rigidbody::FixedUpdate(glm::vec2 gravity, float timeStep) 
{ 
    if (m_isKinematic) 
        return; 
    ...
    ...
}
```
 
If this was all we did, it would mostly look like a passible simulation, but moving objects would collide with static objects in a soggy dissipative manner, and collisions would get progressively worse.

This is because the static object will still take some of the kinetic energy of the collision without then using it. Its internal variables for linear and angular velocity would still be updated, but it wouldn’t appear to move. 

We should zero linear and angular velocity every frame for a static object.

This effectively removes energy from the simulation. The best way to work around this is to rule that static objects have infinite mass and moment of intertia for collision purposes. 

So we want to zero the velocities in *FixedUpdate()* 

```c++
void Rigidbody::FixedUpdate(glm::vec2 gravity, float timeStep) 
{ 
    if (m_isKinematic) 
    { 
        m_velocity = glm::vec2(0); 
        m_angularVelocity = 0; 
        return; 
    }
...
... 
```

To simulate infinite mass, we can either set the mass of a static object to a very large value in its constructor, or modify the *GetMass()* function to return a very large value for static objects. We’ll do the latter, since that allows us to make runtime changes to an object’s kinematic state. 

Modify the *Rigidbody* class header as follows: 

```c++
    glm::vec2 GetPosition() const { return m_position; } 
    glm::vec2 GetVelocity() { return m_velocity; } 
    float GetMass() { return m_isKinematic ? INT_MAX : m_mass; } 
    
    float GetOrientatation() { return m_orientation; } 
    float GetAngularVelocity() { return m_angularVelocity; } 
    float GetMoment() { return m_isKinematic ? INT_MAX : m_moment; } 
```
 
Check that you’ve been using *GetMass()* and *GetMoment()* in your collision code rather than directly referencing m_mass and m_moment and you should have good crisp collisions with any static objects that you set up.

(This might not be the case if you’ve been following these tutorials, so do check this thoroughly!)

## Activity 1: Bounce Pads

A fully elastic Circle dropped vertically on to a kinematic world-axis-aligned *Box* should bounce up and down as if it was on a *Plane*. If you haven’t used *GetMass()* and *GetMoment()* correctly everywhere in your collision resolution code, this won’t happen correctly. 

## Activity 2: Physics Buckets

Create some other static objects and test your simulation by causing some collisions with various shapes.