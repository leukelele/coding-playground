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
port = 52587
username = "ctf-player"
password = "84b12bae"

ssh_client = ssh_connect(hostname, port, username, password)

if ssh_client:
  command = "cd drop-in && ls -R | while read filename; do ./decrypt.sh ./files/$filename 2>/dev/null; done | grep picoCTF"
  ssh_execute_command(ssh_client, command)
