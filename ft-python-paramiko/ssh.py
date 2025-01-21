import paramiko


def ssh_connect(hostname, port, username, password):
  client = paramiko.SSHClient()
  client.set_missing_host_key_policy(paramiko.AutoAddPolicy())
  try:
    client.connect(hostname, port=port, username=username, password=password)
    print("Connected to", hostname)
    return client
  except paramiko.AuthenticationException:
    print("Authentication failed when connecting to", hostname)
  except paramiko.SSHException as e:
    print("Could not connect to", hostname, ":", str(e))
  except Exception as e:
    print("Error:", str(e))
  return None


def ssh_execute_command(client, command):
  try:
    stdin, stdout, stderr = client.exec_command(command)
    print(stdout.read().decode())
    client.close()
  except paramiko.SSHException as e:
    print("Error executing command:", str(e))


hostname = "rhea.picoctf.net"
port = 61375
username = "ctf-player"
password = "6dd28e9b"

ssh_client = ssh_connect(hostname, port, username, password)

if ssh_client:
  command = "ls -al"
  ssh_execute_command(ssh_client, command)
