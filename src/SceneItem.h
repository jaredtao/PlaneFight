#pragma once
#include <QImage>
#include <QQuickPaintedItem>
#include <QVector>
class SceneItem : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(bool running READ running WRITE setRunning NOTIFY runningChanged)
    Q_PROPERTY(int breadSpeed READ breadSpeed WRITE setBreadSpeed NOTIFY breadSpeedChanged)
    Q_PROPERTY(int trophySpeed READ trophySpeed WRITE setTrophySpeed NOTIFY trophySpeedChanged)
    Q_PROPERTY(int level READ level WRITE setLevel NOTIFY levelChanged)
    Q_PROPERTY(int score READ score WRITE setScore NOTIFY scoreChanged)
    Q_PROPERTY(int breadCount READ breadCount WRITE setBreadCount NOTIFY breadCountChanged)
    Q_PROPERTY(int trophyCount READ trophyCount WRITE setTrophyCount NOTIFY trophyCountChanged)
public:
    SceneItem(QQuickItem *parent = nullptr);

    void paint(QPainter *painter) override;
    void timerEvent(QTimerEvent *e) override;

    Q_INVOKABLE void createBread(int x, int y);
    Q_INVOKABLE void createTrophy(int x, int y);

    bool running() const
    {
        return m_running;
    }

    int breadSpeed() const
    {
        return m_breadSpeed;
    }

    int trophySpeed() const
    {
        return m_trophySpeed;
    }

    int level() const
    {
        return m_level;
    }

    int score() const
    {
        return m_score;
    }

    int trophyCount() const
    {
        return m_trophyCount;
    }

    int breadCount() const
    {
        return m_breadCount;
    }

signals:
    void getScore();
    void lose();

    void runningChanged(bool running);

    void breadSpeedChanged(int breadSpeed);

    void trophySpeedChanged(int trophySpeed);

    void levelChanged(int level);

    void scoreChanged(int score);

    void trophyCountChanged(int trophyCount);

    void breadCountChanged(int breadCount);

public slots:

    void setRunning(bool running);
    void setBreadSpeed(int breadSpeed);

    void setTrophySpeed(int trophySpeed);

    void setLevel(int level);

    void setScore(int score);

    void setTrophyCount(int trophyCount);

    void setBreadCount(int breadCount);

protected:
    void move();

private:
    QImage m_bread;
    QImage m_trophy;
    QList<QRect> m_breadPos;
    QList<QRect> m_trophyPos;
    bool m_running = false;
    int m_breadSpeed = 1;
    int m_trophySpeed = 1;
    int m_level = 1;
    int m_score = 0;
    int m_trophyCount = 0;
    int m_breadCount = 0;
};
