#include <cstdio>
void updateWave (const double timeInterval, double* x, double* speed)
{
    //wave translation
    (*x) += timeInterval * (*speed);

    //wall collision
    if((*x) > 1.0)
    {
        (*speed) *= -1.0;
        (*x) += 1.0 +timeInterval * (*speed);
    } else if((*x) < 0.0)
    {
        (*speed) *= -1.0;
        (*x) += timeInterval * (*speed);
    }

}

int main()
{
    double x = 0.0;
    double y = 1.0;
    double speedX = 1.0;
    double speedY = -0.5;

    const int fps = 60;
    const double timeInterval = 1.0/fps;

    for (int i = 0; i<1000; ++i)
    {
        //wave update
        updateWave(timeInterval, &x, &speedX);
        updateWave(timeInterval, &y, &speedY);
    }
    return 0;
}
