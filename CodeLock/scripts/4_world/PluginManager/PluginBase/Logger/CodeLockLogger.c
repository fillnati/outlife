class CodeLockLogger extends PluginBase {
	private int year, month, day, hour, minute, second;
	private ref array<string> filePaths;
	private const ref array<string> subDirectories = { "Access", "Attach", "Raid", "Synch", "Admin" };
	private const string logFolderDir = "$profile:\\CodeLock\\Logs\\";
	private const string fileType = ".log";

	void CodeLockLogger() {
		if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

		filePaths = new array<string>();

		if (!FileExist(CLConst.clModFolder)) {
			MakeDirectory(CLConst.clModFolder);
		}

		if (!FileExist(logFolderDir)) {
			MakeDirectory(logFolderDir);
		}
		CheckAndCreateSubDirectories();
	}

	private void CheckAndCreateSubDirectories() {
		if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

		GetYearMonthDay(year, month, day);
		GetHourMinuteSecond(hour, minute, second);

		for (int i = 0; i < subDirectories.Count(); i++) {
			string subDirectory = subDirectories[i];
			string directory = logFolderDir + subDirectory;
			if (!FileExist(directory)) {
				MakeDirectory(directory);
			}
			if (!CheckExistingFile(directory, subDirectory)) {
				CreateNewLogFile(directory, subDirectory);
			}
		}
	}

	private bool CheckExistingFile(string directory, string subDirectory) {
		FindFileHandle findFileHandler;
		string filePattern, fileName, dateFormat, dateTimeFormat;
		int fileAttr, flags;

		dateFormat = "[" + month.ToStringLen(2) + "-" + day.ToStringLen(2) + "-" + year.ToStringLen(2) + "]";
		dateTimeFormat = dateFormat + "[" + hour.ToStringLen(2) + "." + minute.ToStringLen(2) + "." + second.ToStringLen(2) + "]";
		filePattern =  directory + "\\" + dateFormat + "*" + fileType;
		findFileHandler = FindFile(filePattern, fileName, fileAttr, flags);

		if (fileName != string.Empty) {
			string logDir = directory + "\\" + fileName;
			FileHandle logFile = OpenFile(logDir, FileMode.APPEND);

			filePaths.Insert(logDir);
			
			FPrintln(logFile, dateTimeFormat + " Log file reloaded ( Server Restart )");
			CloseFile(logFile);
			return true;
		}
		return false;
	}

	private void CreateNewLogFile(string directory, string subDirectory) {
		if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

		string dateTimeFormat = "[" + month.ToStringLen(2) + "-" + day.ToStringLen(2) + "-" + year.ToStringLen(2) + "]" + "[" + hour.ToStringLen(2) + "." + minute.ToStringLen(2) + "." + second.ToStringLen(2) + "]";
		string logFileName = dateTimeFormat + " " + subDirectory + fileType;
		string creationText = dateTimeFormat + " New " + subDirectory + " Log File Created!";
		string logDir = directory + "\\" + logFileName;

		filePaths.Insert(logDir);
		FileHandle logFile = OpenFile(logDir, FileMode.WRITE);
		FPrintln(logFile, creationText);
		CloseFile(logFile);
	}

	void WriteLog(string type, PlayerIdentity playerId = null, vector pos = "0 0 0", string accessType = "", bool claim = false, bool cut = false, float damage = 0, float health = 0) {
		if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

		GetYearMonthDay(year, month, day);
		GetHourMinuteSecond(hour, minute, second);
		string timeFormat = "[" + hour.ToStringLen(2) + ":" + minute.ToStringLen(2) + ":" + second.ToStringLen(2) + "]";
		string startText = "Player (" + playerId.GetName() + ", " + playerId.GetPlainId() + ")";
		string logDir;
		string logText;

		type.ToLower();
		switch (type) {
			case "access":
				{
					logDir = filePaths[0];
					accessType.ToLower();

					switch (accessType) {
						case "setcode":
							{
								logText = startText + "(" + pos + ")" + " set a new passcode on lock!";
								break;
							}
						case "notowner":
							{
								logText = startText + "(" + pos + ")" + " attempted to change the passcode to a lock they do not own!";
								break;
							}
						case "entercode":
							{
								logText = startText + "(" + pos + ")" + " accessed a lock!";
								break;
							}
						case "claimowner":
							{
								logText = startText + "(" + pos + ")" + " claimed ownership of a lock!";
								break;
							}
						case "addguest":
							{
								logText = startText + "(" + pos + ")" + " was added as a guest of a lock!";
								break;
							}
						case "removelock":
							{
								logText = startText + "(" + pos + ")" + " removed a lock!";
								break;
							}
						case "changecode":
							{
								logText = startText + "(" + pos + ")" + " changed the passcode on a lock! Clearing all guests...";
								break;
							}
						default:
							{
								logText = startText + "(" + pos + ")" + " quick accessed a lock!";
								break;
							}
					}
					break;
				}
			case "attach":
				{
					logDir = filePaths[1];
					logText = startText + "(" + pos + ")" + " attached a lock!";
					break;
				}
			case "raid":
				{
					logDir = filePaths[2];

					if (!cut) {
						logText = startText + "(" + pos + ")" + " is raiding lock! CodeLock HP: " + health + " Damage Done: " + damage;
					} else {
						logText = startText + "(" + pos + ")" + " successfully raided lock!";
					}
					break;
				}
			case "synch":
				{
					logDir = filePaths[3];
					logText = startText + "(" + pos + ")" + " requested data for lock!";
					break;
				}
			case "admin":
				{
					startText = "Admin (" + playerId.GetName() + ", " + playerId.GetPlainId() + ")";
					logDir = filePaths[4];
					accessType.ToLower();

					switch (accessType) {
						case "open":
							{
								logText = startText + "(" + pos + ")" + " opened a lock!";
								break;
							}
						case "change":
							{
								logText = startText + "(" + pos + ")" + " change passcode of a lock!";
								break;
							}
						case "remove":
							{
								logText = startText + "(" + pos + ")" + " removed a lock!";
								break;
							}
						case "join":
							{
								logText = startText + " joined the server!";
								break;
							}
						default:
							{
								logText = startText + "(" + pos + ")" + " used admin on lock!";
								break;
							}
					}
					break;
				}
		}
		FileHandle logFile = OpenFile(logDir, FileMode.APPEND);
		FPrintln(logFile, timeFormat + " " + logText);
		CloseFile(logFile);
	}
}

CodeLockLogger GetCodeLockLogger() {
	if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return null; }
	return CodeLockLogger.Cast(GetPlugin(CodeLockLogger));
}