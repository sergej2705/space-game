#pragma once

#include <curses.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "Firinglane.h"
#include "Player.h"

using namespace std;

int width = 10;
int height = 5;

class SpaceGame
{
public:
  SpaceGame(int difficulty) : m_player(Player(2, 1, width, height))
  {
    m_difficulty = difficulty;

    m_health = 6 - m_difficulty;

    m_tickLength = 300 - m_difficulty * 50;

    m_length = 50;
    m_width = width;
    m_height = height;

    m_lanes = {};
    for (int i = 0; i < m_difficulty; i++)
    {
      m_lanes.push_back(Firinglane(m_length, &m_health));
    }

    initscr();
    curs_set(0);
    m_gamearea = newwin(m_height + 2, m_width + 2, 0, 0);
    refresh();
    wrefresh(m_gamearea);
    keypad(stdscr, TRUE);
    noecho();
  }

  ~SpaceGame()
  {

    wclear(m_gamearea);
    endwin();
  }

  void start()
  {
    system("clear");

    print(m_gamearea);
    mvaddstr(m_height + 2, 0, string("Move to start").c_str());

    halfdelay(100);

    int input;
    while (((input = getch()) != 'q') && m_health > 0)
    {
      switch (input)
      {
      case KEY_DOWN:
        m_player.moveDown();
        break;
      case KEY_UP:
        m_player.moveUp();
        break;
      case KEY_LEFT:
        m_player.moveLeft();
        break;
      case KEY_RIGHT:
        m_player.moveRight();
        break;
      case ' ':
        break;
      }

      if (m_player.getPositionX() == 1 && m_player.getPositionY() == 1)
      {
        m_player.loadEnergy(3);
      }

      for (int i = 0; i < m_lanes.size(); i++)
      {
        Firinglane &lane = m_lanes.at(i);
        int y = getFiringlaneY(i);

        if (m_player.getPositionX() == m_width && m_player.getPositionY() == y)
        {
          int energy = m_player.unloadEnergy();
          lane.load(energy);
        }

        lane.tick();
      }

      print(m_gamearea);
      // addstr(string(m_health).c_str());
      halfdelay(3);
    }

    clear();

    int score = m_lanes.at(0).getPassedTicks();
    int highScore = getHighScore();

    if (score > highScore)
    {
      setHighScore(score);
      mvaddstr(1, 0, string("You hit the jackpot and set the new highscore with " + to_string(score) + "!").c_str());
      mvaddstr(3, 0, string("The old highscore was " + to_string(highScore)).c_str());
    }
    refresh();

    string end;
    cin >> end;
  }

private:
  int getHighScore()
  {
    int score = 0;

    string line;
    ifstream scoreFile("score.sav");
    if (scoreFile.is_open())
    {
      getline(scoreFile, line);
      score = stoi(line);
    }
    scoreFile.close();

    return score;
  }

  void setHighScore(int score)
  {
    ofstream scoreFile("score.sav");
    if (scoreFile.is_open())
    {
      scoreFile << to_string(score);
    }
    scoreFile.close();
  }

  int getFiringlaneY(int i)
  {
    return (i + 1) * 2 - 1;
  }

  void print(WINDOW *w)
  {
    wclear(w);
    clear();
    box(w, 0, 0);

    mvwaddch(w, 1, 1, 'x');

    for (int i = 0; i < m_lanes.size(); i++)
    {
      Firinglane &lane = m_lanes.at(i);
      int y = getFiringlaneY(i);

      mvwaddch(m_gamearea, y, m_width, 'x');
      mvaddstr(y, m_width + 2, lane.print().c_str());
    }

    mvwaddch(w, m_player.getPositionY(), m_player.getPositionX(), m_player.hasEnergy() ? '0' : 'O');

    refresh();
    wrefresh(w);
  }

  Player m_player;

  int m_width;
  int m_height;
  int m_difficulty;
  int m_tickLength;
  int m_length;
  int m_health;
  WINDOW *m_gamearea;
  vector<Firinglane> m_lanes;
};
