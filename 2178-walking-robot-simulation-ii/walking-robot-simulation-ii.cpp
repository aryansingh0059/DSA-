class Robot {
public:
    int w, h, x, y;
    int dir; // 0=East, 1=North, 2=West, 3=South
    int cycle;

    Robot(int width, int height) {
        w = width;
        h = height;
        x = 0;
        y = 0;
        dir = 0;
        cycle = 2 * (w + h - 2);
    }

    void step(int num) {
        if (cycle == 0) return;

        num %= cycle;

        // special case
        if (num == 0 && (x != 0 || y != 0)) return;
        if (num == 0 && x == 0 && y == 0) {
            dir = 3; // South
            return;
        }

        int dist = num;

        while (dist > 0) {
            if (dir == 0) { // East
                int move = min(dist, w - 1 - x);
                x += move;
                dist -= move;
                if (dist > 0) dir = 1;
            }
            else if (dir == 1) { // North
                int move = min(dist, h - 1 - y);
                y += move;
                dist -= move;
                if (dist > 0) dir = 2;
            }
            else if (dir == 2) { // West
                int move = min(dist, x);
                x -= move;
                dist -= move;
                if (dist > 0) dir = 3;
            }
            else { // South
                int move = min(dist, y);
                y -= move;
                dist -= move;
                if (dist > 0) dir = 0;
            }
        }
    }

    vector<int> getPos() {
        return {x, y};
    }

    string getDir() {
        if (dir == 0) return "East";
        if (dir == 1) return "North";
        if (dir == 2) return "West";
        return "South";
    }
};