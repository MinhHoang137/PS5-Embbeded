class DeviceHandler:
    def execute(self, action):
        try:
            action.execute()
        except Exception as e:
            print(f"[ERROR] Failed to execute action: {e}")
