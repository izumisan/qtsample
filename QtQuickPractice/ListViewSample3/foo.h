#ifndef FOO_H
#define FOO_H

#include <QObject>
#include <QString>
#include <QColor>

class Foo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)

public:
    Foo() = default;
    Foo( const QString& name, const QColor& color )
        : m_name(name),
          m_color(color)
    {
    }

signals:
    void nameChanged();
    void colorChanged();

public:
    QString name() const
    {
        return m_name;
    }
    void setName( const QString& value )
    {
        if ( m_name != value )
        {
            m_name = value;
            emit nameChanged();
        }
    }

    QColor color() const
    {
        return m_color;
    }
    void setColor( const QColor& value )
    {
        if ( m_color != value )
        {
            m_color = value;
            emit colorChanged();
        }
    }

private:
    QString m_name = "white";
    QColor m_color = QColor( Qt::white );
};

#endif // FOO_H
