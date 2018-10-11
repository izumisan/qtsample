#ifndef FOO_H
#define FOO_H

#include <QObject>
#include <QDebug>

class Foo : public QObject
{
    Q_OBJECT

    // QMLからアクセスできるようにするため、Q_PROPERTYマクロで
    // - getterメソッド
    // - setterメソッド
    // - 変更通知シグナル
    // をそれぞれ設定する
    //
    // Q_PROPERTY( プロパティの型 QMLでアクセスする際のプロパティ名 READ getterメソッド名 WRITE setterメソッド名 NOTIFY 変更通知シグナル名 )
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)

public:
    Foo() {}

signals:
    void valueChanged();

public:

    int value() const
    {
        return m_value;
    }

    void setValue( const int value )
    {
        if ( m_value != (int)value )
        {
            m_value = value;

            emit valueChanged();
        }
    }

private:
    int m_value = 50;  // 初期値
};

#endif // FOO_H
