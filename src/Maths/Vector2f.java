package Maths;

/**
 * Created by steppers on 28/10/15.
 */
public class Vector2f {

    public float x, y;

    public Vector2f(float x, float y)
    {
        this.x = x;
        this.y = y;
    }

    public Vector2f add(float x, float y)
    {
        this.x += x;
        this.y += x;
        return this;
    }

    public Vector2f add(Vector2f v)
    {
        this.x += v.x;
        this.y += v.y;
        return this;
    }

    public Vector2f sub(float x, float y)
    {
        this.x -= x;
        this.y -= x;
        return this;
    }

    public Vector2f sub(Vector2f v)
    {
        this.x -= v.x;
        this.y -= v.y;
        return this;
    }

    public Vector2f mul(float m)
    {
        this.x *= m;
        this.y *= m;
        return this;
    }

}
