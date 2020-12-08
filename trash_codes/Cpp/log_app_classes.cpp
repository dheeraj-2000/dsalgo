#include<iostream>
using namespace std;

class Log{
public:
      enum Level{
            LevelError = 0, LevelWarning, LevelInfo
      };
//       const int LogLevelError = 0;
//       const int LogLevelWarning = 1;
//       const int LogLevelInfo = 2;
private:
      Level m_LogLevel = LevelInfo;

public:
      void Setlevel(Level level){
            m_LogLevel = level;
      }

      void error(const char* message){
            if( m_LogLevel >= LevelError)
                  cout<< "[ERROR]! " << message<<endl;
      }

      void warn(const char* message){
            if( m_LogLevel >= LevelWarning)
                  cout<< "[WARNING]! " << message<<endl;
      }

      void info (const char* message){
            if( m_LogLevel >= LevelInfo)
                  cout<< "[INFO]! " << message<<endl;
      }
};

int main(){
      Log log;
      log.Setlevel(log.LevelInfo);
      log.error("hello D, This is a error");
      log.warn("hello D, This is a warning");
      log.info("hello D, This is a info");
}
