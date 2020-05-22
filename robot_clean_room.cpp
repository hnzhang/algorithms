//using backtrack
#include <unordered_set>
class Robot {
public:
    Robot(std::vector<std::vector<int>>& room, size_t row, size_t col)
        :m_room(room)
        , m_row(row)
        , m_col(col)
        , m_dir(0)
    {}
    // Returns true if the cell in front is open and robot moves into the cell.
        // Returns false if the cell in front is blocked and robot stays in the current cell.
    bool move() {
        switch (m_dir)
        {
        case 0://north
            if (m_row == 0  || m_room[m_row-1][m_col] == 0 ) {//try to moving north
                return false;
            }
            m_row -= 1;
            return true;
        case 1://west
            if (m_col == 0 || m_room[m_row][m_col - 1] == 0) {
                return false;
            }
            m_col -= 1;
            return true;
        case 2://move south
            if (m_row + 1 == m_room.size() || m_room[m_row + 1][m_col] == 0) {
                return false;
            }
            m_row += 1;
            return true;
        case 3:
            if (m_col + 1 == m_room[m_row].size() || m_room[m_row][m_col+1] == 0) {
                return false;
            }
            m_col += 1;
            return true;
        }
        return false;
    }
    // Robot will stay in the same cell after calling turnLeft/turnRight.
    // Each turn will be 90 degrees.
    void turnLeft() {
        m_dir += 1;
        m_dir %= 4;
    }
    void turnRight() {
        m_dir -= 1;
        m_dir %= 4;
    }

    // Clean the current cell.
    void clean() {
        m_room[m_row][m_col] = -1;
    }

    std::vector<std::vector<int>>& m_room;
    size_t m_row;
    size_t m_col;
    int m_dir;//0(north)-1(west)-2(south)-3(east)
};

typedef std::pair<int, int> grid_coordinate;
struct grid_coordinate_hash {
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2>& p) const {
        return std::hash<T1>()(p.first) ^ std::hash<T2>()(p.second);
    }
};

typedef std::unordered_set<std::pair<int, int>, grid_coordinate_hash> grid_history;

class Solution {
public:
    void goback(Robot& robot) {
        robot.turnLeft();
        robot.turnLeft();
        robot.move();
        robot.turnLeft();
        robot.turnLeft();
    }
    void backtrack(Robot& robot, grid_history& history, int row, int col, int dir) {
        auto pair = std::make_pair(row, col);
        history.insert(pair);

        robot.clean();
                                //0(north)-1(west)-2(south)-3(east)
        int directions[4][2] = { {0,1},{-1,0},{0,-1},{1,0} };
        for (int i = 0; i < 4; i++) {
            int new_dir = (dir + i) % 4;
            int new_row = row + directions[new_dir][0];
            int new_col = col + directions[new_dir][1];
            auto new_pair = std::make_pair(new_row, new_col);
            if (history.find(new_pair) == history.end() && robot.move()) {
                backtrack(robot, history, new_row, new_col, new_dir);
                goback(robot);
            }
            robot.turnLeft();
        }
    }

    void cleanRoom(Robot& robot) {
        grid_history history;
        backtrack(robot, history, 0, 0, 0);
    }
};

int main()
{
    std::vector<std::vector<int>> room = {
        {1, 1, 1, 1, 1, 0, 1, 1} ,
        {1, 1, 1, 1, 1, 0, 1, 1},
        {1, 0, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1}
    };
    int row = 1, col = 3;
    Robot robot(room, row, col);
    Solution s;
    s.cleanRoom(robot);
}
