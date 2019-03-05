#ifndef CONFIRMATION_H
#define CONFIRMATION_H

#include <QObject>
#include <QString>
#include <QVariant>

class Confirmation : public QObject
{
    Q_OBJECT
    Q_PROPERTY( QString title READ title NOTIFY titleChanged )
    Q_PROPERTY( QVariant content READ content WRITE setContent NOTIFY contentChanged )
signals:
    void titleChanged() const;
    void contentChanged() const;
    void done( const int resultCode );

public:
    explicit Confirmation( QObject* parent = nullptr );
    Confirmation( const QString& title, QObject* parent = nullptr );
    Confirmation( const QString& title, const QVariant& content, QObject* parent = nullptr );
    virtual ~Confirmation() = default;

public:
    QString title() const;
    void setTitle( const QString& value );
    QVariant content() const;
    void setContent( const QVariant& value );
    bool confirmed() const;

public slots:
    void close( const int resultCode );

private:
    QString m_title = {};
    QVariant m_content = {};
    bool m_confirmed = false;
};

#endif // CONFIRMATION_H
