import os, shutil

theFolder = 'build'

folders = os.listdir('.')

for folder in folders:
    if os.path.isdir(folder):
        file_path = os.path.join(folder, theFolder)
        print( 'Deleting folowing directory: ' + file_path)
        try:
            if os.path.isdir(file_path): 
                shutil.rmtree(file_path)
        except Exception as e:
            print(e)
    
        if not os.path.isdir(file_path):
            os.mkdir(file_path)

 