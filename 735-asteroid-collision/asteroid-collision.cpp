class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // int n =  asteroids.size();
        bool collisionHappened = true;
        while (collisionHappened) {
            collisionHappened = false;
        for(int i = 0; i < (int)asteroids.size() - 1; i++){
            if(asteroids[i] > 0 && asteroids[i+1] < 0){
                collisionHappened = true;
                int leftAsteroid = asteroids[i];
                int rightAsteroid = abs(asteroids[i+1]);
                if(leftAsteroid > rightAsteroid){
                    asteroids.erase(asteroids.begin() + i+1);
                }
                else if(leftAsteroid < rightAsteroid){
                    asteroids.erase(asteroids.begin() + i);
                }
                else{
                    asteroids.erase(asteroids.begin() + i, asteroids.begin() + i + 2);
                }
                break;
            }
        }
        }
        return asteroids;
    }
};