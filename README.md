# Zeltina_Unreal_Network_Test

## 🎮 UE5 C++ 1:1 네트워크 평가 과제
* **Game Rule**: 60초 제한 시간 내에 상대보다 더 많은 아이템을 획득하면 승리하는 **1:1 리슨 서버(Listen Server)** 경쟁 게임입니다.
* **Server Logic**: `NetGameMode`와 `NetSpawner`를 통해 게임 시간을 관리하고 3초마다 맵에 **아이템을 랜덤 스폰**합니다.
* **Replication**: `GameState`를 활용하여 남은 시간과 양측 플레이어의 점수를 **모든 클라이언트 화면(HUD)에 실시간 동기화**했습니다.
* **UI System**: `PlayerController`가 로컬 위젯을 관리하며, 게임 종료 시 승/무/패를 판정하여 **결과 UI를 개별 출력**합니다.
* **Tech Stack**: Unreal Engine 5, C++, RPC(Server/Multicast), Property Replication, UMG
