#ifndef CONFIRMATION_H
#define CONFIRMATION_H

#include <functional>
#include <QObject>
#include <QString>
#include <QVariant>

class Confirmation : public QObject
{
    Q_OBJECT
    Q_PROPERTY( QString title READ title NOTIFY titleChanged )
    Q_PROPERTY( QVariant content READ content WRITE setContent NOTIFY contentChanged )
    Q_PROPERTY( int resultCode READ resultCode WRITE setResultCode NOTIFY resultCodeChanged )
signals:
    void titleChanged() const;
    void contentChanged() const;
    void resultCodeChanged() const;

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
    int resultCode() const;
    void setResultCode( const int& value );

    void setAcceptedAction( const std::function<void()>& action ) { m_accepted = action; }
    void setRejectedAction( const std::function<void()>& action ) { m_rejected = action; }

public slots:
    virtual void accepted() const { invoke( m_accepted ); }
    virtual void rejected() const { invoke( m_rejected ); }

public:
    bool isAccepted() const;
    bool isRejected() const;

private:
    void invoke( const std::function<void()>& action ) const;

private:
    QString m_title = {};
    QVariant m_content = {};
    int m_resultCode = 0;

    std::function<void()> m_accepted = nullptr;
    std::function<void()> m_rejected = nullptr;
};

#endif // CONFIRMATION_H
