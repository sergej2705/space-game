#pragma once

class Player
{
public:
  Player(int startX, int startY)
  {
    m_position_x = startX;
    m_position_y = startY;
    m_bound_x = 0;
    m_bound_y = 0;
    m_energy = 0;
  }

  ~Player()
  {
  }

  int getPositionX()
  {
    return m_position_x;
  }

  int getPositionY()
  {
    return m_position_y;
  }

  void loadEnergy(int energy)
  {
    m_energy = energy;
  }

  int unloadEnergy()
  {
    int energy = m_energy;
    m_energy = 0;
    return energy;
  }

  bool hasEnergy()
  {
    return m_energy > 0;
  }

  void moveLeft()
  {
    if (m_position_x - 1 >= 1)
    {
      m_position_x--;
    }
  }

  void moveRight()
  {
    if (m_position_x + 1 <= m_bound_x)
    {
      m_position_x++;
    }
  }

  void moveUp()
  {
    if (m_position_y - 1 >= 1)
    {
      m_position_y--;
    }
  }

  void moveDown()
  {
    if (m_position_y + 1 <= m_bound_y)
    {
      m_position_y++;
    }
  }

  void setBound(int x, int y)
  {
    m_bound_x = x;
    m_bound_y = y;
  }

private:
  int m_position_x;
  int m_position_y;
  int m_bound_x;
  int m_bound_y;
  int m_energy;
};
